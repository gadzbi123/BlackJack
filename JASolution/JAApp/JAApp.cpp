#include "pch.h"

#include <stdio.h>
#include <windows.h>
#include <emmintrin.h>	//  SSE2 instructions library header
#include <vector>
#include <bitset>
#include <array>
#include <string>
#include <intrin.h>

extern "C" int _stdcall CheckSSEAsm(void);
extern "C" double _stdcall RadToDegAsm(double rad);

#define M_PI   3.14159265358979323846264338327950288

class InstructionSet
{
    class InstructionSet_Internal;

public:
    static bool SSE3(void) { return CPU_Rep.f_1_ECX_[0]; }
    static bool SSSE3(void) { return CPU_Rep.f_1_ECX_[9]; }
    static bool SSE41(void) { return CPU_Rep.f_1_ECX_[19]; }
    static bool SSE42(void) { return CPU_Rep.f_1_ECX_[20]; }
    static bool SSE(void) { return CPU_Rep.f_1_EDX_[25]; }
    static bool SSE2(void) { return CPU_Rep.f_1_EDX_[26]; }
private:
    static const InstructionSet_Internal CPU_Rep;

    class InstructionSet_Internal
    {
    public:
        InstructionSet_Internal()
            : nIds_{ 0 },
            f_1_ECX_{ 0 },
            f_1_EDX_{ 0 },
            data_{}
        {
            std::array<int, 4> cpui;

            __cpuid(cpui.data(), 0);
            nIds_ = cpui[0];

            for (int i = 0; i <= nIds_; ++i)
            {
                __cpuidex(cpui.data(), i, 0);
                data_.push_back(cpui);
            }

            if (nIds_ >= 1)
            {
                f_1_ECX_ = data_[1][2];
                f_1_EDX_ = data_[1][3];
            }
        };
        int nIds_;
        std::bitset<32> f_1_ECX_;
        std::bitset<32> f_1_EDX_;
        std::vector<std::array<int, 4>> data_;

    };
};

const InstructionSet::InstructionSet_Internal InstructionSet::CPU_Rep;

bool CheckSSECpp()
{
    bool check = 0;
    if (
        InstructionSet::SSE() &&
        InstructionSet::SSE2() &&
        InstructionSet::SSE3() &&
        InstructionSet::SSE41() &&
        InstructionSet::SSE42() &&
        InstructionSet::SSSE3()
        )
    {
        check = 1;
    }
    return check;

}
double RadToDegNMEACpp(double dRad, bool bSSE2)
{
    double dDeg = 0.0;

    double dRem = 0.0, dx;
    int    nDeg;
    if (bSSE2) {
        __m128d ma, mb, mDeg, mx, my, mz, mk;

        ma = _mm_set_sd(180.0);
        mb = _mm_set_sd(M_PI);
        mDeg = _mm_div_pd(ma, mb);          //  convert rad to deg  deg = rad*180/pi

        ma = _mm_set_sd(dRad);
        mb = _mm_mul_pd(ma, mDeg);
        dDeg = mb.m128d_f64[0];             // rad to deg

        nDeg = (int)dDeg;                   // abs (dMLng)
        dRem = dDeg - nDeg;                   // rem (dMLng)

        ma = _mm_set_sd(100.0);
        mb = _mm_set_sd(60.0);
        mx = _mm_set_sd(dRem);
        mz = _mm_mul_pd(mx, mb);          // dGPS*60
        dx = nDeg * 100;
        mk = _mm_set_sd(dx);
        my = _mm_add_pd(mk, mz);          // nDeg*100+dGPS*60
        dDeg = my.m128d_f64[0];             // convert to degmmin.ssdec NMEA format
    }
    else {
        double dCnv = 180.0 / M_PI;

        dDeg = dRad * dCnv;

        nDeg = (int)dDeg;
        dRem = dDeg - nDeg;
        dDeg = nDeg * 100 + dRem * 60;
    }

    return dDeg;


} // End of RadToDegNMEACpp

int main()
{
	
    printf("SSE with assebler- %s\n", (CheckSSEAsm() == 1 ? "supported" : "not supported"));
    printf("SSE with cpp- %s\n", (CheckSSECpp()? "supported" : "not supported"));

	double RadValue = 1.5;
	//printf("Assembler: RadValue=%f, DegValue=%f\n", RadValue, RadToDegAsm(RadValue));
	printf("Cpp: RadValue=%f, DegValue=%f\n", RadValue, RadToDegNMEACpp(RadValue,1));
}
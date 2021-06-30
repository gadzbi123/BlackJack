#define M_PI   3.14159265358979323846264338327950288
#include <emmintrin.h>	//  SSE2 instructions library header
#include <iostream>

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
    float RadValue = M_PI/3;
    std::cout<<"RadValue="<<RadValue<<", DegValue=" << RadToDegNMEACpp(RadValue, 1);
}


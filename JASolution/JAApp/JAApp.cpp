#include "pch.h"

#include <windows.h>
#include <stdio.h>
extern "C" int _stdcall FindChar_1(void);
extern "C" int _stdcall FindChar_2(void);
extern "C" int _stdcall FindChar_3(LPSTR String);
extern "C" int _stdcall FindChar_4(void);
extern "C" int _stdcall FindChar_5(void);
extern "C" int _stdcall FindChar_6(void);
extern "C" int _stdcall ReadTime_1(void);
extern "C" int _stdcall ReadTime_3(LPSTR String);

int main()
{
	char szString[] = { 'A','G','I','K','S','Z','J', 0xFF }; // definicja ciagu znakow 

	printf("FindChar_1 %s\n", (FindChar_1() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_2 %s\n", (FindChar_2() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_3 %s\n", (FindChar_3(szString) ? "Found J" : "Not Found J"));
	printf("FindChar_4 %s\n", (FindChar_4() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_5 %s\n", (FindChar_5() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_6 %s\n", (FindChar_6() == 1 ? "Found J" : "Not Found J"));

	printf("Czas przetwarzania: %i\n", ReadTime_3(szString));
	printf("Czas przetwarzania: %i\n", ReadTime_3(szString));
	printf("Czas przetwarzania: %i\n", ReadTime_3(szString));
	printf("Czas przetwarzania: %i\n", ReadTime_3(szString));
	printf("Czas przetwarzania: %i\n", ReadTime_3(szString));
	printf("Czas przetwarzania: %i\n", ReadTime_3(szString));
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());

	//MessageBox(NULL, L"Wyci�gnij wnioski", L"Lab. 2", MB_OK);

}
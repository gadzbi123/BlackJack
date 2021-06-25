#include "pch.h"
#include "Resource.h"
#include "JAApp.h"

int main()
{
	char szString[] = { 'A','G','I','K','S','Z','J', 0xFF }; // definicja ciagu znakow 

	printf("FindChar_1 %s\n", (FindChar_1() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_2 %s\n", (FindChar_2() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_3 %s\n", (FindChar_3(szString) ? "Found J" : "Not Found J"));
	printf("FindChar_4 %s\n", (FindChar_4() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_5 %s\n", (FindChar_5() == 1 ? "Found J" : "Not Found J"));
	printf("FindChar_6 %s\n", (FindChar_6() == 1 ? "Found J" : "Not Found J"));

	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());
	printf("Czas przetwarzania: %i\n", ReadTime_1());

	MessageBox(NULL, L"Wyci¹gnij wnioski", L"Lab. 2", MB_OK);
}
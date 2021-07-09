#pragma once
#include <iostream>
#include <fstream>	//do i z pliku
#include <vector>	//wektory
#include <iterator> //iteratory
#include <string>	//string
#include <algorithm>//sort, unique
using namespace std;

class funkcje_pomocnicze
{
public:
	//switch ktory pozwala wybrac uzytkownikowi pore dnia i typ jedzenia
	void switch_wybor_typu_pory_dnia(int& _tof, int& _tod);
	//wypisuje vector napisow z poprzednim wypisaniem numeru i kropki
	void wypisz_vector_str_counted(vector<string>x);
};


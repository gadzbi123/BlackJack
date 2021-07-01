#pragma once
#include"FoodType.h"
class Przepisy
{
	//otwiera konkretny przepis
	void open_przepis(string, int _tof);
	//pozwala wybrac przepis z vectora, zwraca wartosc wyboru z drugiego parametru
	void wybierz_przepis(vector<string>, int&);
	//wypisuje szukane przepisy w 3 kategoriach
	void wypisz_przepisy(vector<string>foodNameVec, int wege_count, int vegan_count, int meat_count);
	//dodaje do odpowiednie miejsce w pliku przepis podany przez uzytkownika
	void insert_przepis_into_file(int,int);
public:
	void find_przepis();
	void dodaj_przepis();

};


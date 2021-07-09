#pragma once
#include "funkcje_pomocnicze.h"
#include "FoodType.h"
class Przepisy
{
private:
	vector<string> vec_begin_file;
	vector<string> vec_end_file;
	vector<string> vec_wlasny_przepis;
private:
	//otwiera konkretny przepis
	void open_przepis(string, int _tof);
	//pozwala wybrac przepis z vectora, zwraca wartosc wyboru z drugiego parametru
	void wybierz_przepis(vector<string>, int&);
	//wypisuje szukane przepisy w 3 kategoriach
	void wypisz_przepisy(vector<string>foodNameVec, int wege_count, int vegan_count, int meat_count);
	//dodaje do odpowiednie miejsce w pliku przepis podany przez uzytkownika, type_of_food
	void insert_przepis_into_file(int);
	//zapisuje zawartosc pliku do 2 wektorow tej klasy, int_nr1 to type of food and int_nr2 to timeOfDay
	void zapisz_plik_z_przepisami(int,int);
	//pomaga uzytkownikowi stworzyc nowy przepis zadajac serie pytan
	void stworz_wlasny_przepis();
public:
	//wyszukuje ilosc przepisow ktore znajduja sie w plikach o danej nazwie
	void find_przepis();
	//funkcja korzysta z wielu funkcji aby dodac zawartosc przepisu do pliku
	void dodaj_przepis();
	~Przepisy() { vec_begin_file.clear(); vec_end_file.clear(); vec_wlasny_przepis.clear(); };
};


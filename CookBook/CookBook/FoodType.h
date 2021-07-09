#pragma once
#include "funkcje_pomocnicze.h"

//Typ dania
class FoodType
{

public:
	int timeOfDay; //0-sniadanie, 1-obiad, 2-kolacja
	int typeOfFood;//0-wege, 1-wegan, 2-miesne
private:
	//pozwala wybrac skladnik z vectora i zwraca vector nazw przepisow posiadajacych dany skladnik
	vector<string> find_ingredient_in_file(string);
	//pozwala wybrac produkt z wektora produktow, zwraca nazwe tego produktu
	string choose_ingredient(vector<string>);
public:
	//ustawia czas dnia
	void SetTimeOfDay(int);
	//otrzymujemy czas dnia
	int getTimeOfDay();
	//funkcja wykonuje wyszukanie przepisu po skladniku
	void ingredients();
	//konstruktor bez parametru
	FoodType() :timeOfDay(-1) ,typeOfFood(-1){}
	//konsturktor z parametrami time_of_day i type_of_food
	FoodType(int _tod, int _tof) : timeOfDay(_tod), typeOfFood(_tof) {};
	//otrzymujemy czas dnia z funkcji
	string getTimeOfDayStr();
};

//Typ wege ktora dziedziczy z typu jedzenia
class WegeType: public FoodType
{
public:
	WegeType(int _tod) : FoodType(_tod,0) {}

};

//Typ vegan ktory dziedziczy z typu jedzenia
class VeganType : public FoodType
{
public:
	VeganType(int _tod) : FoodType(_tod, 1) {}

};

//Typ miesny, ktory dziedziczy z typu jedzenia
class MeatType : public FoodType
{
public:
	MeatType(int _tod) : FoodType(_tod, 2) {}

};

#pragma once
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Typ dania
class FoodType
{

public:
	int timeOfDay; //0-sniadanie, 1-obiad, 2-kolacja
	int typeOfFood;//0-wege, 1-wegan, 2-miesne
private:
	//pozwala wybrac skladnik z vectora i zwraca vector nazw przepisow posiadajacych dany skladnik
	vector<string> find_ingredient_in_file(string);
	string choose_ingredient(vector<string>);
public:
	void SetTimeOfDay(int);
	int getTimeOfDay();
	void ingredients();
	FoodType() :timeOfDay(-1) ,typeOfFood(-1){}
	FoodType(int _tod, int _tof) : timeOfDay(_tod), typeOfFood(_tof) {};
	string getTimeOfDayStr();
};

class WegeType: public FoodType
{
public:
	void ingredients();
	WegeType(int _tod) : FoodType(_tod,0) {}

};

class VeganType : public FoodType
{
public:
	void ingredients();
	VeganType(int _tod) : FoodType(_tod, 1) {}

};

class MeatType : public FoodType
{
public:
	void ingredients();
	MeatType(int _tod) : FoodType(_tod, 2) {}

};

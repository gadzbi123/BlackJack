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
	void SetTimeOfDay(int);
	int getTimeOfDay();
	virtual void ingredients() = 0;
	FoodType() :timeOfDay(-1) {}
	FoodType(int _Tod) : timeOfDay(_Tod) {}
};

class WegeType: public FoodType
{
public:
	void ingredients();
	WegeType(int _tod) : FoodType(_tod) {}

};

class VeganType : public FoodType
{
public:
	void ingredients();
};

class MeatType : public FoodType
{
public:
	void ingredients();
};

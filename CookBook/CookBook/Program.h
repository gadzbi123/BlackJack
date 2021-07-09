#pragma once
#include"FoodType.h"
#include"Przepisy.h"
#include"funkcje_pomocnicze.h"

class Program
{
private:
	//pierwszy parametr dla funkcji main, wykonuje wyszukanie przepisu po produkcie
	void find_food_with_ingradient();
	//drugi parametr dla funckji main, wykonuje otwarcie plikow do sczytania przepisu 
	void open_food_recipe();
	//dodaje przepis do plikow w zaleznosci od tego jaki to plik
	void add_food_recipe();
public:
	//glowny program
	void main();
};


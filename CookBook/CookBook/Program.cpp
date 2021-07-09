#include "Program.h"

void Program::find_food_with_ingradient()
{
	int type_of_food, time_of_day;
	funkcje_pomocnicze f;
	FoodType* food=nullptr;

	f.switch_wybor_typu_pory_dnia(type_of_food, time_of_day);

	switch (type_of_food)
	{
	case 0:
		food = new WegeType(time_of_day);
		break;
	case 1:
		food = new VeganType(time_of_day);
		break;
	case 2:
		food = new MeatType(time_of_day);
		break;
	}

	food->ingredients();

}

void Program::open_food_recipe()
{
	Przepisy przepis;
	przepis.find_przepis();
}

void Program::add_food_recipe()
{
	Przepisy przepis;
	przepis.dodaj_przepis();
}

void Program::main()
{
    char option = '1';

    while (option != '0')
    {
        cout << "Wybierz jedna z opcji:\n"
            << "1- wyszukaj nazwy przepisu po skladnikach\n"
            << "2- otworz przepis podajac nazwe\n"
            << "3- dodaj przepis do ksiazki kucharskiej\n"
            << "0- wyjdz\n";

        cin >> option;
        switch (option)
        {
        case '0':
            return;
        case '1':
            find_food_with_ingradient();
            break;
        case '2':
            open_food_recipe();
            break;
        case '3':
            add_food_recipe();
            break;
        default:
            cout << "Zly parametr\n";
        }
    }
}

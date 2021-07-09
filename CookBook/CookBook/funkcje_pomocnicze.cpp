#include "funkcje_pomocnicze.h"

void funkcje_pomocnicze::switch_wybor_typu_pory_dnia(int& _tof, int& _tod)
{
	int option;
	while (true) {
		cout << "Podaj jakiego typu jest twoja potrawa" << endl
			<< "typy potrawy: " << endl
			<< "1- wegetarjanskie" << endl
			<< "2- weganskie" << endl
			<< "3- miesne" << endl
			<< "twoj wybor: " << endl;

		if (cin >> option)
		{
			if (option > 3 or option < 1)
				cout << "takiego typu nie ma na liscie" << endl;
			else
				break;
		}
		else
		{
			cout << "Podaj wartosc liczbowa" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	option--;
	_tof = option;

	while (true) {
		cout << "Podaj na jaka pore dnia jest posilek" << endl
			<< "czasy dnia: " << endl
			<< "1- sniadanie" << endl
			<< "2- obiad" << endl
			<< "3- kolacja" << endl
			<< "twoj wybor: " << endl;

		if (cin >> option)
		{
			if (option > 3 or option < 1)
				cout << "takiego typu nie ma na liscie" << endl;
			else
				break;
		}
		else
		{
			cout << "Podaj wartosc liczbowa" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	option--;
	_tod = option;
}

void funkcje_pomocnicze::wypisz_vector_str_counted(vector<string>x)
{
	for (int i = 0; i < x.size(); i++)
		cout << i + 1 << "." << x[i] << endl;
}
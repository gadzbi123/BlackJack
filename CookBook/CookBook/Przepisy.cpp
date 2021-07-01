#include "Przepisy.h"
void wypisz_vector_str_counted(vector<string>x);

void Przepisy::find_przepis()
{
	string nameFood,line,foodName;
	vector<string> foodNameVec;
	int wege_count=0, vegan_count=0, meat_count=0,choice;
	cout << "Podaj nazwe przepisu (moze byc czesc nazwy)" << endl;
	cin >> nameFood;

	ifstream plik;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			plik.open("../przepisy/wege.txt");
		if (i == 1)
			plik.open("../przepisy/wegan.txt");
		if (i == 2)
			plik.open("../przepisy/miesne.txt");

		if (!plik)
		{
			cout << "nie otwarto pliku" << endl;
			return;
		}
		else
		{
			while (getline(plik, line, '-'))
			{
				getline(plik, line);
				if (line.find(nameFood) != string::npos)
				{
					if (i == 0)
						wege_count++;
					if (i == 1)
						vegan_count++;
					if (i == 2)
						meat_count++;
					foodNameVec.push_back(line);
				}
			}
		}
		plik.close();
	}

	wypisz_przepisy(foodNameVec, wege_count, vegan_count, meat_count);

	wybierz_przepis(foodNameVec,choice);
	int _tof;
	if (choice < wege_count)
		_tof = 0;
	if(vegan_count != 0)
		if (choice < (wege_count + vegan_count) and choice >= wege_count )
			_tof = 1;
	if (meat_count != 0)
		if (choice < (wege_count + vegan_count + meat_count) and choice >= (wege_count + vegan_count))
			_tof = 2;
	cout << "TOF: " <<_tof<<endl;
	open_przepis(foodNameVec[choice], _tof);
}

void Przepisy::open_przepis(string, int _tof)
{
}

void Przepisy::wybierz_przepis(vector<string>foodNameVec, int& choice)
{
	while (true) {
		cout << "Wybierz przepis, ktory chcesz obejrzec" << endl << "przepis nr: ";
		if (cin >> choice)
		{
			if (choice > foodNameVec.size() or choice < 1)
				cout << "tego produktu nie ma na liscie" << endl;
			else
			{
				choice--;
				break;
			}
		}
		else
		{
			cout << "Podaj wartosc liczbowa" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void Przepisy::wypisz_przepisy(vector<string>foodNameVec,int wege_count,int vegan_count,int meat_count)
{
	int i, j = 0;
	if (wege_count > 0)
	{
		cout << "Potrawy wege:\n";
		for (i = j; i < j + wege_count; i++)
			cout << i + 1 << "." << foodNameVec[i] << endl;
		j = i;
	}

	if (vegan_count > 0)
	{
		cout << "Potrawy Vegan:\n";
		for (i = j; i < j + vegan_count; i++)
			cout << i + 1 << "." << foodNameVec[i] << endl;
		j = i;
	}

	if (meat_count > 0)
	{
		cout << "Potrawy miesne:\n";
		for (i = j; i < j + meat_count; i++)
			cout << i + 1 << "." << foodNameVec[i] << endl;
		j = i;
	}
	cout << endl;
}

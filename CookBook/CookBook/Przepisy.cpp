#include "Przepisy.h"

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
	//cout << "TOF: " <<_tof<<endl;
	open_przepis(foodNameVec[choice], _tof);
}



void Przepisy::open_przepis(string foodName, int _tof)
{
	string line;
	ifstream plik;
	if (_tof == 0)
		plik.open("../przepisy/wege.txt");
	if (_tof == 1)
		plik.open("../przepisy/wegan.txt");
	if (_tof == 2)
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
			if (line.find(foodName) != string::npos)
			{
				cout << foodName << ":" << endl<<endl;
				getline(plik, line);
				line.assign(line, 2, line.size() - 2);
				cout <<"Sposob przyrzadzenia" <<endl << line<<endl;
				while (getline(plik, line))
				{
					if (line[0] == '%')
						break;
					cout << line<<endl;
				}
				line.assign(line, 1, line.size() - 1);
				cout << "Skladniki" << endl<<line<<endl;
				while (getline(plik, line))
				{
					if (line[0] == '+' or line[0] =='-')
						break;
					cout << line << endl;
				}
				break;
			}
		}
	}
	plik.close();
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
		cout << "Potrawy vegan:\n";
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

void Przepisy::dodaj_przepis()
{
	int option, _tof, _tod;
	funkcje_pomocnicze f;

	f.switch_wybor_typu_pory_dnia(_tof, _tod);

	zapisz_plik_z_przepisami(_tof, _tod);
	stworz_wlasny_przepis();
	insert_przepis_into_file(_tof);//ZMIENIC -1 na _tof
}

void Przepisy::insert_przepis_into_file(int _tof)
{
	ofstream plik;

	if (_tof == -1)
		plik.open("../przepisy/nowe.txt");
	if (_tof == 0)
		plik.open("../przepisy/wege.txt");
	if (_tof == 1)
		plik.open("../przepisy/wegan.txt");
	if (_tof == 2)
		plik.open("../przepisy/miesne.txt");

	if (!plik)
	{
		cout << "nie otwarto pliku" << endl;
		return;
	}
	else
	{	
		for (int i = 0; i < vec_begin_file.size(); i++)
			plik << vec_begin_file[i];
		
		for (int i = 0; i < vec_wlasny_przepis.size(); i++)
			plik << vec_wlasny_przepis[i];

		for (int i = 0; i < vec_end_file.size(); i++)
			plik << vec_end_file[i];			
		
	}
}

void Przepisy::zapisz_plik_z_przepisami(int _tof,int _tod)
{
	ifstream plik;
	string line;

	FoodType temp(_tod,_tof);
	string tod_str = "+" + temp.getTimeOfDayStr();

	if (_tof == 0)
		plik.open("../przepisy/wege.txt");
	if (_tof == 1)
		plik.open("../przepisy/wegan.txt");
	if (_tof == 2)
		plik.open("../przepisy/miesne.txt");

	if (!plik)
	{
		cout << "nie otwarto pliku" << endl;
		return;
	}
	else
	{
		while (getline(plik, line))
		{
			if (line.find(tod_str) == string::npos)
			{
				vec_begin_file.push_back(line+'\n');
			}
			else
			{
				vec_begin_file.push_back(line+"\n\n");
			

				while (getline(plik, line))
					vec_end_file.push_back(line+'\n');
			}
		}
		plik.close();
	}

}

void Przepisy::stworz_wlasny_przepis()
{
	string input,word;
	
	cout << "Podaj nazwe przepisu"<<endl;
	cin >> input;

	input = "-" + input;
	vec_wlasny_przepis.push_back(input+'\n');
	cin.get();

	cout << "Podaj sposob przyrzadzenia" << endl;
	getline(cin, input);

	input = "= " + input;
	vec_wlasny_przepis.push_back(input+"\n\n");

	cout << "Podaj skladniki po spacji" << endl;
	getline(cin, input);

	input = "%" + input;

	for (auto x : input)
	{		
			if (x == ' ')
			{
				word += '\n';
				vec_wlasny_przepis.push_back(word);
				word = "";
			}
			else
				word = word + x;	
	}

	if (word.size() > 0)
		vec_wlasny_przepis.push_back(word+"\n\n");
}

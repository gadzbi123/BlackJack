#include "FoodType.h"
void wypisz_vector_str_counted(vector<string>x);

void FoodType::ingredients()
{
	string nameTod,line,foodName,ingredName;
	vector<string> ingredNameVec,foodNameVec;

	nameTod = getTimeOfDayStr();

	ifstream plik;
	if (typeOfFood == -1)
		return;
	if (typeOfFood == 0)
		plik.open("../przepisy/wege.txt");
	if (typeOfFood == 1)
		plik.open("../przepisy/wegan.txt");
	if (typeOfFood == 2)
		plik.open("../przepisy/miesne.txt");

	if (!plik)
	{
		cout << "nie otwarto pliku" << endl;
		return;
	}
	else
	{
		findFoodTime:
		while (getline(plik, line,'+'))
		{
			getline(plik, line);
			if (line != nameTod)
				goto findFoodTime;

			cout << "foodtime:" << line << endl;

			while (getline(plik, line, '-'))
			{
				getline(plik, line);
				foodName = line;
				newFoodType:
				while (getline(plik, line, '%'))
				{
					getline(plik, line);
					
					if (line != "\n")
						ingredNameVec.push_back(line);

					while (getline(plik, line))
					{
						if (line[0] == '+')
							goto leaveLoop;
						if (line[0] == '-')
						{
							goto newFoodType;
						}
						if(line !="\n")
							ingredNameVec.push_back(line);
					}
				}
			}
			leaveLoop:
			cout << "ingSize=" << ingredNameVec.size()<<endl;

			//sort to remove errors
			sort(ingredNameVec.begin(), ingredNameVec.end());
			//delete repeatable content
			auto ip = unique(ingredNameVec.begin(), ingredNameVec.end());
			//change size of vector
			ingredNameVec.resize(std::distance(ingredNameVec.begin(), ip));
			//remove '\n'
			ingredNameVec.erase(ingredNameVec.begin());

			wypisz_vector_str_counted(ingredNameVec);

			ingredName=choose_ingredient(ingredNameVec);
			cout << "ingredName:" << ingredName<<endl;
			foodNameVec = find_ingredient_in_file(ingredName);

			wypisz_vector_str_counted(foodNameVec);
			plik.close();
		}
	}
}

void FoodType::SetTimeOfDay(int tod)
{
	this->timeOfDay = tod;
}

int FoodType::getTimeOfDay()
{
	return timeOfDay;
}

string FoodType::getTimeOfDayStr()
{
	string name;
	int tod = timeOfDay;
	switch (tod)
	{
	case 0:
		name = "Sniadanie";
		break;
	case 1:
		name = "Obiad";
		break;
	case 2:
		name = "Kolacja";
		break;
	default:
		name.clear();
		cout << "Nie ustawiono pory dnia" << endl;
	}
	return name;
}

string FoodType::choose_ingredient(vector<string>ingredNameVec)
{
	string ingredName;
	int input;
	while (true) {
		cout << "Ktory produkt chcesz wybrac do przepisu?" << endl<<"nr produktu: ";
		if (cin >> input)
		{
			if (input > ingredNameVec.size() or input < 1)
				cout << "tego produktu nie ma na liscie"<<endl;
			else
				break;
		}
		else
		{
			cout << "Podaj wartosc liczbowa"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return ingredName=ingredNameVec[input-1];
}

vector<string> FoodType::find_ingredient_in_file(string ingredName)
{
	vector<string> foodNameVec;
	string foodName,line;
	string nameTod = getTimeOfDayStr();

	ifstream plik;
	if (typeOfFood == -1)
		return foodNameVec;
	if (typeOfFood == 0)
		plik.open("../przepisy/wege.txt");
	if (typeOfFood == 1)
		plik.open("../przepisy/wegan.txt");
	if (typeOfFood == 2)
		plik.open("../przepisy/miesne.txt");

	if (!plik)
	{
		cout << "nie otwarto pliku w choose_ingredient()" << endl;
		return foodNameVec;
	}
	else
	{
	findFoodTime:
		while (getline(plik, line, '+'))
		{
			getline(plik, line);
			if (line != nameTod)
				goto findFoodTime;

			cout << "foodtime:" << line << endl;

			while (getline(plik, line, '-'))
			{
				getline(plik, line);
			newFoodType:
				foodName = line;
				while (getline(plik, line, '%'))
				{	
					while (getline(plik, line))
					{
						if (line[0] == '+')
							goto leaveLoop;
						if (line[0] == '-')
						{
							line.assign(line, 1,line.size()-1);
							goto newFoodType;
						}
						if (line.find(ingredName) != string::npos)
							foodNameVec.push_back(foodName);
					}
				}
			}
		}
	leaveLoop:
		plik.close();
		cout << "rozmiarVecfoodName:" << foodNameVec.size()<<endl;
		return foodNameVec;
	}
}

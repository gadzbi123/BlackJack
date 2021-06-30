#include "FoodType.h"
void WegeType::ingredients()
{
	int tod = this->getTimeOfDay();
	string nameTod,line,foodName;
	vector<string> foodNameList,ingredNameList;

	switch (tod)
	{
	case 0:
		nameTod = "Sniadanie";
		break;
	case 1:
		nameTod = "Obiad";
		break;
	case 2:
		nameTod = "Kolacja";
		break;
	default:
		cout << "Nie ustawiono pory dnia" << endl;
		return;
	}

	ifstream plik("../przepisy/wege.txt");
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
				cout << "foodtype:" << line << endl;
				foodName = line;
				newFoodType:
				while (getline(plik, line, '%'))
				{
					getline(plik, line);
					
					if (line != "\n")
						ingredNameList.push_back(line);

					while (getline(plik, line))
					{
						if (line[0] == '+')
							goto leaveLoop;
						if (line[0] == '-')
						{
							goto newFoodType;
						}
						if(line !="\n")
							ingredNameList.push_back(line);
					}
				}
			}
			leaveLoop:
			cout << "ingSize=" << ingredNameList.size()<<endl;

			sort(ingredNameList.begin(), ingredNameList.end());
			auto ip = unique(ingredNameList.begin(), ingredNameList.end());
			ingredNameList.resize(std::distance(ingredNameList.begin(), ip));
			
			//remove '\n'
			ingredNameList.erase(ingredNameList.begin());
			for (int i = 0; i < ingredNameList.size(); i++)
			{
				cout << ingredNameList[i]<<endl;
			}


			
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

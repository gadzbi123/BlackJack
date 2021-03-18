#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LiczbaZesp
{
public:
	double Re, Im;
public:
	LiczbaZesp(double R, double I) :Re(R), Im(I) {}
	friend bool operator<(const LiczbaZesp& first, const LiczbaZesp& second)
	{
		double z1 = sqrt(first.Re * first.Re + first.Im * first.Im);
		double z2 = sqrt(second.Re * second.Re + second.Im * second.Im);
		return z1 > z2;
	}
};

std::ostream& operator<<(std::ostream& os, const LiczbaZesp& zesp)
{
	os << "Re: " << zesp.Re << ", Im: " << zesp.Im << std::endl;
	return os;
}

template <class T>
void wypisz(vector<T>a)
{
	
	for (auto iter = a.begin(); iter < a.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << "\n";
}

void increment(int& i)
{
	i++;
}

int main()
{
	//Zad 1
	vector<int>liczby = { 1,10,30,10,40,20 };
	wypisz(liczby);

	//Zad 2
	for_each(liczby.begin(), liczby.end(), increment);
	wypisz(liczby);

	sort(liczby.begin(), liczby.end());
	wypisz(liczby);

	bool jestDwa = binary_search(liczby.begin(), liczby.end(), 2);
	cout << "Czy wystapila dwojka: " << boolalpha << jestDwa<<endl;

	replace(liczby.begin(), liczby.end(), 11, 99);
	wypisz(liczby);

	bool jest_posortowana = is_sorted(liczby.begin(), liczby.end());
	cout << "Wektor posortowany? " << boolalpha << jest_posortowana<<endl;

	auto graniczny=minmax_element(liczby.begin(), liczby.end());
	cout << "najmniejszy graniczny: " << *graniczny.first << " najwiekszy graniczny: " << *graniczny.second << endl;

	liczby.resize(liczby.size() + 3, 77);
	wypisz(liczby);

	//Zad 3
	vector<char>znaki = { 'a','H','q','c','G' };
	sort(znaki.begin(), znaki.end());
	wypisz(znaki); //duze litery maja mniejsza wartosc niz male w kodzie ASCII wiec sa na poczatku

	vector<string>ciagi_znakow = { "jan","marek","franek","adam","weronika" };
	sort(ciagi_znakow.begin(),ciagi_znakow.end());
	wypisz(ciagi_znakow); //Ulożone alfabetycznie

	//Zad 4
	vector<LiczbaZesp>LZ =
	{
		LiczbaZesp(2,1.5),
		LiczbaZesp(5,3.5),
		LiczbaZesp(2.2,1),
		LiczbaZesp(0,1.7),
		LiczbaZesp(22,-15)
	};
	wypisz(LZ);
	cout<<"Pierwsza jest mniejesza? "<<(LZ[1] < LZ[2])<<endl;

	sort(LZ.begin(), LZ.end());
	wypisz(LZ); //Nie jest posortowana - trzeba przeciażyć funkcje
}
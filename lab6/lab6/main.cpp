#include<iostream>
#include<vector>

using namespace std;

//Zad1
class Centrum_Handlowe
{
public:
	int sklepy;
	Centrum_Handlowe() :sklepy(0) { cout << "Konstruktor bezArg" << endl; }
	Centrum_Handlowe(int count) :sklepy(count) { cout << "Konstruktor jednoArg" << endl; }
	~Centrum_Handlowe() { cout << "Destruktor" << endl; }
	void Increment() { this->sklepy++; cout << "Increment" << endl; }
};

//Zad 2,3,4.
void wypisz_wsk(const unique_ptr<Centrum_Handlowe>&x,const string name)
{
	if (x)
		cout << name << ": adres=" << x << " sklepy=" << x->sklepy << endl;
	else
		cout << name << ": adres=nullptr"<<endl;
}

void zadania()
{
	unique_ptr<Centrum_Handlowe>wsk_kl1(new Centrum_Handlowe(10));
	unique_ptr<Centrum_Handlowe>wsk_kl2= make_unique <Centrum_Handlowe>(5);
	unique_ptr<Centrum_Handlowe>wsk_kl3(new Centrum_Handlowe);
	//unique_ptr<A>wsk_kl3 = wsk_kl2; //UNIQUE - wyj¹tkowy
	//unique_ptr<A>wsk_kl3 = move(wsk_kl2); //USUNIE wsk_kl2 ale przypisze do wsk_kl3
	wsk_kl1->Increment();

	wypisz_wsk(wsk_kl1, "wskkl1");
	wypisz_wsk(wsk_kl2, "wskkl2");
	
	//swap
	wsk_kl1.swap(wsk_kl2);
	wypisz_wsk(wsk_kl1, "wskkl1");
	wypisz_wsk(wsk_kl2, "wskkl2");

	//reset
	cout << "Adres przed reset=>";
	wypisz_wsk(wsk_kl1, "wskkl1");
	wsk_kl1.reset();
	cout << "Adres po reset=>";
	wypisz_wsk(wsk_kl1, "wskkl1");

	//release
	cout << "Adres przed release=>";
	wypisz_wsk(wsk_kl2, "wskkl2");
	auto ptr = wsk_kl2.release();
	cout << "Adres po release=>";
	wypisz_wsk(wsk_kl2, "wskkl2");//wyciek
	delete ptr;

	shared_ptr<int>wsk_int1 = make_unique<int>(5);
	shared_ptr<int>wsk_int2 = wsk_int1;
	shared_ptr<int>wsk_int3 = wsk_int1;
	cout<<"Poprzedni wlasciciel:"<<wsk_int3.owner_before(wsk_int1)<<endl;
	wsk_int1.reset();
	cout << "wsk_int1:" << wsk_int1 << endl;
	cout << "wsk_int2:" << wsk_int2 << endl;
	weak_ptr<int>wsk_int4 = wsk_int2;
	cout << wsk_int4.use_count() << endl;

}

//ZAD 5
void wypisz_vec_ptr(vector<shared_ptr<int>> x)
{
	for (const auto p : x) {
		if(p)
			cout << ' ' << *p;
	}
	cout << endl;
}

void wypisz_adresy(vector<shared_ptr<int>> x)
{
	for (const auto p : x)
	{
		if (p)
			cout << ' ' << p;
	}
	cout << endl;
}

void zadanie_5()
{
	vector<shared_ptr<int>>wsk_int;
	for (int i = 0; i < 10; i++)
		wsk_int.push_back(make_shared<int>(rand() % 15));

	wypisz_vec_ptr(wsk_int);
	wypisz_adresy(wsk_int);
	wsk_int[2] = wsk_int[3];
	wsk_int[4] = wsk_int[3];
	weak_ptr<int>weak = wsk_int[3];

	cout << "weak.use_count:" << weak.use_count() << " Adres weak:" << weak.lock() << endl;

	wsk_int[3].reset();
	wsk_int[2].reset();
	cout << "weak.use_count:" << weak.use_count() << " Adres weak:" << weak.lock() << endl;//poniewaz weak.use_count() !=0 to istnieje adres weak.lock()

	wsk_int[4].reset();
	cout << "weak.use_count:" << weak.use_count() << " Adres weak:" << weak.lock() << endl;//weak.use_count()==0 czyli weak.lock()=0

	wypisz_vec_ptr(wsk_int);
	wypisz_adresy(wsk_int);
}

int main()
{
	zadania();
	zadanie_5();
	shared_ptr<int> p1(new int(10),
		[](int* p)
		{
			cout << "Zwolnienie pamieci o adresie" << p<<
				"wskazujaca na wartoœæ" << *p << endl;
			delete p;
		});

	return 0;
}

//reset usuwa obiekt i zeruje wskaznik
//release zwaraca wskaznik i uwalnia sie od niego (nie usuwa)
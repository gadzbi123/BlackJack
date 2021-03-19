#include<iostream>
#include<vector>

using namespace std;
class A
{
public:
	int a;
	A() :a(5) { cout << "Konstruktor bezArg" << endl; }
	A(int x) : a(x) { cout << "Konstruktor jednoArg" << endl; }
	~A() { cout << "Destruktor" << endl; }
	void Increment() { cout << "Increment" << endl; this->a++; }
};

void dzien_1()
{
	unique_ptr<A>wsk_kl1(new A(10));
	unique_ptr<A>wsk_kl2(new A);
	unique_ptr<A>wsk_kl3 = make_unique <A> (5);
	//unique_ptr<A>wsk_kl3 = wsk_kl2; NIE MOZNA PRZYPISAC BO MUSI BYC UNIQUE
	//unique_ptr<A>wsk_kl3 = move(wsk_kl2); USUNIE wsk_kl2 
	wsk_kl1->Increment();



	cout << "wskkl1=" << wsk_kl1->a << endl;
	cout << "wskkl2=" << wsk_kl2->a << endl;
	//swap
	wsk_kl1.swap(wsk_kl2);
	cout << "wskkl1=" << wsk_kl1->a << endl;
	cout << "wskkl2=" << wsk_kl2->a << endl;

	//reset
	cout << "Adres przed reset:" << wsk_kl1.get() << "\n";
	wsk_kl1.reset();
	cout << "Adres po reset:" << wsk_kl1.get() << '\n';

	//release
	cout << "Adres przed release:" << wsk_kl2.get() << "\n";
	auto ptr = wsk_kl2.release();
	cout << "Adres po release:" << wsk_kl2.get() << '\n';//wyciek
	delete ptr;

	//bool s_ptr
	if (wsk_kl1)
		cout << "wskkl1 istnieje" << endl;
	else
		cout << "wskkl1 nie istnieje" << endl;

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

weak_ptr<int> slaby;

void observe()
{
	cout <<"liczba uzyc slabego="<< slaby.use_count() << endl;
	if (auto dzielony = slaby.lock())//przypisz weaka do shared aby go uzyæ potem, nie mozna dzielony = slaby bo to nie jest przypisanie do tego samego typu
		cout << *dzielony << endl;//nie mozna wypisac weaka dlatego uzywamy shared
	else
		cout << "slaby przestal istniec"<<endl;


}

void dzien_2()
{
	{
		auto shared = make_shared<int>(50);
		slaby = shared;
		observe();
	}
	observe();
}

class Centrum_Handlowe
{
public:
	int sklepy;
	Centrum_Handlowe():sklepy(0) { cout << "Konstruktor bezArg" << endl; }
	Centrum_Handlowe(int count) :sklepy(count) { cout << "Konstruktor jednoArg" << endl; }
	~Centrum_Handlowe() { cout << "Destruktor" << endl; }
};

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


void zad5()
{
	vector<shared_ptr<int>>wsk_int;
	for (int i = 0; i < 10; i++)
		wsk_int.push_back(make_shared<int>(rand() % 15));

	wypisz_vec_ptr(wsk_int);
	wsk_int[2] = wsk_int[3];
	wsk_int[4] = wsk_int[3];
	weak_ptr<int>weak = wsk_int[3];
	cout << "weak.use_count:" << weak.use_count() << " Adres weak:" << weak.lock() << endl;
	wsk_int[3].reset();
	wsk_int[2].reset();
	cout << "weak.use_count:" << weak.use_count() << " Adres weak:" << weak.lock() << endl;//poniewaz weak.use_count !=0 to istnieje adres weak.lock
	wsk_int[4].reset();
	cout << "weak.use_count:" << weak.use_count() << " Adres weak:" << weak.lock() << endl;
	wypisz_vec_ptr(wsk_int);
	wypisz_adresy(wsk_int);
}

int main()
{
	//dzien_1();
	//dzien_2();
	
}

//reset usuwa obiekt i zeruje wskaznik
//release zwaraca wskaznik i uwalnia sie od niego (nie usuwa)
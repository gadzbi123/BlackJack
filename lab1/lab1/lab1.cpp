#include <iostream>
using namespace std;
class Firma
{
public:
    int do_uregulowania = 0;

    void uregulowane()
    {
        do_uregulowania = 0;
    }
    virtual ~Firma() = default;
};

class Dostawca : public Firma
{
public:
    virtual void dostawa()//nie wykonuje sie - zastosowalem to aby wiedziec co ma robic metoda
    {
        do_uregulowania--;
    }
};

class Nabywca : public Firma
{
public:
    virtual void sprzedaz()//nie wykonuje sie - zastosowalem to aby wiedziec co ma robic metoda
    {
        do_uregulowania++;
    }
};

class Detal : public Nabywca
{
public:
    void sprzedaz() override
    {
        do_uregulowania += 5500;
    }
};

class Hurt : public Nabywca
{
public:
    void sprzedaz() override
    {
        do_uregulowania += 25500;
    }
};

class Monitory : public Dostawca
{
    void dostawa()
    {
        do_uregulowania -= 12500;
    }
};

class Komputery : public Dostawca
{
    void dostawa()
    {
        do_uregulowania -= 32000;
    }
};

int main()
{
    Monitory monitoryZRajhu;
    Komputery komputer;
    Hurt hurtGliwice, hurtKato;
    Detal* detal = new Detal[3];

    Firma* firmy[] = { &komputer,&monitoryZRajhu,&hurtGliwice,&hurtKato,&detal[0],&detal[1],&detal[2] };

    int wartosc = 0;

    for (auto i : firmy)
    {
        Nabywca* jeden = dynamic_cast<Nabywca*>(i);
        if (jeden)
        {
            jeden->sprzedaz();
            cout << "Nazwa nabywcy i kwota: ";
        }

        Dostawca* drugi = dynamic_cast<Dostawca*>(i);
        if (drugi)
        {
            drugi->dostawa();
            cout << "Nazwa dostawcy i kwota: ";
        }

        cout << typeid(*i).name() << ", " << i->do_uregulowania << " zl\n";//nie podanie wskaznika w typeid() skutkuje wypisaniem wskaznika na firme- klasy rodzica
        wartosc += i->do_uregulowania;
    }
    cout << "Saldo: " << wartosc << " zl\n";
    delete[]detal;
}


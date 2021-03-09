#include <iostream>
using namespace std;

const int liczba = 2;

class Abonent
{
public:
    float CenaAbonamentu, CenaTelefonu, DoZaplaty;
    string Numer;

};

class Blad_numeru
{
public:
    string Nazwa;
};

class ZaDuzaLiczba :public Blad_numeru
{
public:
    ZaDuzaLiczba() { Nazwa = "Za duzo cyfr"; }
};

class ZaMalaLiczba :public Blad_numeru
{
public:
    ZaMalaLiczba() { Nazwa = "Za malo cyfr"; }
};

class BladKonwersji :public Blad_numeru
{
public:
    BladKonwersji() { Nazwa = "Blad Konwersji"; }
};

void DodajAbonenta(Abonent* klienci[])
{
    int numer;
    ZaDuzaLiczba zd();
    ZaMalaLiczba zm();
    BladKonwersji bk();
    for (int i = 0; i < liczba; i++)
    {
        cout << "Podaj Cene Abonamentu, Cene Telefonu, Ilosc do zaplaty oraz Numer: ";
        cin >> klienci[i]->CenaAbonamentu >> klienci[i]->CenaTelefonu;
        if (klienci[i]->CenaAbonamentu <= 0 or klienci[i]->CenaTelefonu <= 0)throw logic_error("Wartosci niedodatnie");

        klienci[i]->DoZaplaty = klienci[i]->CenaAbonamentu + klienci[i]->CenaTelefonu;
        if (klienci[i]->DoZaplaty > 1000)throw runtime_error("Ilosc do zaplaty przekroczyla 1000");

        cin >> klienci[i]->Numer;
        if (klienci[i]->Numer.length() > 9) throw zd;
        if (klienci[i]->Numer.length() < 9) throw zm;

        for (int j = 0; j < klienci[i]->Numer.length(); j++) if (klienci[i]->Numer[j] > '9') throw bk;

    }
}

int main()
{
    bool BezBledu = true;

    Abonent lukasz, jan;
    Abonent* klienci[liczba] = { &lukasz,&jan };

    while (BezBledu)
    {
        try
        {
            DodajAbonenta(klienci);
        }
        catch (logic_error& e)
        {
            cout << "Logic error:" << e.what() << endl;
            BezBledu = false;
        }
        catch (runtime_error& e)
        {
            cout << "Runtime error: " << e.what() << endl;
            BezBledu = false;
        }
        catch (Blad_numeru e)
        {
            cout << "Blad dlugosci numeru" << endl;
            cout << "wyjatek: " << e.Nazwa;
            BezBledu = false;
        }
        catch (...)
        {
            BezBledu = false;
        }
    }
}
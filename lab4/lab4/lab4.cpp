#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <set>
#include <chrono>

using namespace std;
class Ksiazka
{
public:
    int Cena;
    string Nazwa;


    Ksiazka(int cena, string nazwa) :Nazwa(nazwa), Cena(cena) {}
    Ksiazka() {}
   
};

ostream& operator<<(ostream& output, const Ksiazka* K) 
{
    output << "Nazwa: " << K->Nazwa << " Cena: " << K->Cena << endl;
    return output; 
}

void posortuj(vector<Ksiazka*>& wek)
{
    if (wek.size() == 0 || wek.size() == 1)
        return;
    else
    {
        Ksiazka* buff=nullptr;
        for(int i=0;i<wek.size()-1;i++)
            for (int j = 0; j < wek.size() - 1; j++)
                if (wek[j]->Cena > wek[j + 1]->Cena)
                {
                    buff = wek[j];
                    wek[j] = wek[j + 1];
                    wek[j + 1] = buff;
                }
        buff = nullptr;
    }
    
}

int main()
{
    //ZAD 1
    std::default_random_engine los,los2;
    los.seed(1337);
    los2.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(1, 99);
    std::uniform_int_distribution<int> distr2(1, 10);

    vector<Ksiazka*>wektor;
    for (int i = 0; i < 10; i++)
        wektor.push_back(new Ksiazka(distr(los), "Encyklopedia " + to_string(i)));

    for (int i = 0; i < 10; i++)
        cout << wektor[i];

    posortuj(wektor);
    cout << "Posortowane:" << endl;
    for (int i = 0; i < 10; i++)
        cout << wektor[i];

    //ZAD 2
    set<Ksiazka*>secik;
    multiset<Ksiazka*>multisecik;
    for (int i = 0; i < 10; i++)
    {
        int zmienna = distr2(los2);
        secik.insert(new Ksiazka(zmienna, "Elementarz " + to_string(i)));
        multisecik.insert(new Ksiazka(zmienna, "MultiElementarz " + to_string(i)));
    }
    cout << "Rozmiar setu: " << secik.size() << " Rozmiar multisetu: " << multisecik.size() << endl;

    //ZAD 3
    vector <vector<int>>matrix;
    int size = 0;
    cout << "Podaj rozmiar macierzy: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        vector<int>column;
        for (int j = 0; j < size; j++)
        {
            matrix.push_back(column);
            if (i == j)
                matrix[j].push_back(1);
            else
                matrix[j].push_back(0);
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j];
        cout << endl;
    }
}


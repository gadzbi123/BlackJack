
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<shared_ptr<int>> wek_int()
{
    vector<shared_ptr<int>> w;
    shared_ptr<int> p1(new int(5));
    shared_ptr<int> p2(new int(6));
    
    w.push_back(p1);
    w.push_back(p2);

    return w;
}

int main()
{
    auto wek = wek_int();
    for (int i = 0; i < wek.size(); i++)
        cout << *wek[i] << " ";
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

#include "Entity.h"
#include "Player.h"
#include "Dealer.h"
#include "Windows.h"
#include "Zero.h"
#include "First.h"
#include "Second.h"
#include "Third.h"

void save_to_file(vector<Entity*> vec_ent)
{
    ofstream plik("Salda.txt", ios_base::out);
    if (plik)
    {
        for(int i=1;i<vec_ent.size();i++)
            plik << vec_ent[i]->get_name() << '\n'<<vec_ent[i]->get_money()<<endl;

    }
    plik.close();
}

int main()
{
    sf::RenderWindow display(sf::VideoMode(800, 600), "", sf::Style::Close | sf::Style::Titlebar);
    vector<Entity*> entities;

   /* vector<int> v;
    vector<string> n;
    for(int i = 1 ; i < 4; i++)
        n.push_back("name+"+to_string(i));
    for (int i = 1; i < 4; i++)
        v.push_back(10*i);

    entities = createEntities(n, v);

    for (int i = 1; i < 4; i++)
        entities[i]->set_bet(2 + i);*/
    
    Windows* window = new Zero;
    window->Screen(display,entities);

    if (entities.empty())
    {
        window = new First;
        window->Screen(display, entities);
    }
    
    while (display.isOpen())
    {
        window = new Second;
        window->Screen(display, entities);
        if (display.isOpen())
        {
            window = new Third;
            window->Screen(display, entities);
        }
    }
}
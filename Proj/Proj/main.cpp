#include "Entity.h"
#include "Player.h"
#include "Dealer.h"
#include "Windows.h"
#include "First.h"
#include "Second.h"
#include "Third.h"

class Calculate
{
    vector<int> points;
public:
    Calculate(vector<Entity*> vec_ent) 
    { 
        for(int i=0;i<vec_ent.size();i++)
            points.push_back(0);
    }
    void add(int ent_number)
    {

    }
};

int main()
{
    sf::RenderWindow display(sf::VideoMode(800, 600), "", sf::Style::Close | sf::Style::Titlebar);
    vector<Entity*> entities;

    vector<int> v;
    vector<string> n;
    for(int i = 1 ; i < 4; i++)
        n.push_back("name+"+to_string(i));
    for (int i = 1; i < 4; i++)
        v.push_back(10*i);

    entities = createEntities(n, v);

    for (int i = 1; i < 4; i++)
        entities[i]->set_bet(2 + i);
    
    Windows* window;/*= new First;
    window->Screen(display, entities);
    window = new Second;
    window->Screen(display,entities);*/
    window = new Third;
    window->Screen(display,entities);

}

//gdy ustawiam bet to zmniejszac money
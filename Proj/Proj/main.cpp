#include "Entity.h"
#include "Player.h"
#include "Dealer.h"
#include "Windows.h"
#include "First.h"
#include "Second.h"

vector<string> vec_name_cards()
{
    vector<string> names_of_cards;

    //loop for numbers
    for (int i = 2; i < 11; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
                names_of_cards.push_back(to_string(i) + "h"); //hearts
            if (j == 1)
                names_of_cards.push_back(to_string(i) + "s"); //spades
            if (j == 2)
                names_of_cards.push_back(to_string(i) + "c"); //clubs
            if (j == 3)
                names_of_cards.push_back(to_string(i) + "d"); //diamonds
            
        }
    }

    //loop for figures
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)//Jacks
            {
                if (j == 0)
                    names_of_cards.push_back("Jh"); //hearts
                if (j == 1)
                    names_of_cards.push_back("Js"); //spades
                if (j == 2)
                    names_of_cards.push_back("Jc"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Jd"); //diamonds
            }

            if (i == 1)//Queens
            {
                if (j == 0)
                    names_of_cards.push_back("Qh"); //hearts
                if (j == 1)
                    names_of_cards.push_back("Qs"); //spades
                if (j == 2)
                    names_of_cards.push_back("Qc"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Qd"); //diamonds
            }

            if (i == 2)//Kings
            {
                if (j == 0)
                    names_of_cards.push_back("Kh"); //hearts
                if (j == 1)
                    names_of_cards.push_back("Ks"); //spades
                if (j == 2)
                    names_of_cards.push_back("Kc"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Kd"); //diamonds
            }

            if (i == 3)//Aces
            {
                if(j == 0)
                 names_of_cards.push_back("Ah"); //hearts
                if (j == 1)
                    names_of_cards.push_back("As"); //spades
                if (j == 2)
                    names_of_cards.push_back("Ac"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Ad"); //diamonds
            }
        }
    }
    return names_of_cards;
}

class Card {

    sf::RectangleShape Shape;
    sf::Texture Texture;
    string Name;
public:
    Card(): Name("")
    {
        sf::Vector2f x(60.0f, 90.0f);
        Shape.setSize(x);
    }
    Card(string name) : Name(name)
    {
        sf::Vector2f x(60.0f, 90.0f);
        Shape.setSize(x);
        //this->setTextureRect
    }
    string get_name() { return this->Name; }
    bool is_card();
    void random();
    sf::RectangleShape get_Rec();
   
};

void Card::random()
{
    string _name="";
    int x;

    std::default_random_engine los;
    los.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(1,13),distr2(0,3);

    x = distr(los);
    if (x == 1)
        _name += "A";
    if (x > 1 && x < 11)
        _name += to_string(x);
    if (x == 11)
        _name += "J";
    if (x == 12)
        _name += "Q";
    if (x == 13)
        _name += "K";

    x = distr2(los);
    if (x == 0)
        _name += "h";
    if (x == 1)
        _name += "s";
    if (x == 2)
        _name += "c";
    if (x == 3)
        _name += "d";

    this->Name = _name;
}

sf::RectangleShape Card::get_Rec()
{
    return this->Shape;
}

bool Card::is_card()
{
    vector<string> cards = vec_name_cards();
    for (int i = 0; i < cards.size(); i++)
    {
        if (this->Name == cards[i])
            return true;
    }
    return false;
}

class Third : public Windows {
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent, vector<sf::Text>& vec_txt) override;
    virtual void Screen2() {};

};

void Third::Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent, vector<sf::Text>& vec_txt)
{
    cout << vec_txt.size();
    
    vector<Card> cards; //4 vektory
    Card card;
    int startPos = 250;

    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 3; i++)
        {
            card.get_Rec().setFillColor(sf::Color::Red);
            card.get_Rec().setPosition(10 + i * 70, 475 - j * 100);//x + 3 karty oddalone od sb o 70, y - 4 karty oddalone od sb o 100 
            cards.push_back(card);

        }

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Enter)
                {
                    return;
                }
            }
        }


        window.clear(sf::Color(0, 100, 50, 250));

        for (int i = 0; i < vec_txt.size(); i++)
            window.draw(vec_txt[i]);
        
        for(int i=0;i<cards.size();i++)
            window.draw(cards[i].get_Rec());
        window.display();
    }
}

int main()
{
    sf::RenderWindow display(sf::VideoMode(800, 600), "", sf::Style::Close | sf::Style::Titlebar);
    vector<Entity*> entities;
    vector<sf::Text> texts;

    vector<int> v;
    vector<string> n;
    for(int i = 1 ; i < 4; i++)
        n.push_back("name+"+to_string(i));
    for (int i = 1; i < 4; i++)
        v.push_back(10*i);
    entities = createEntities(n, v);

    Card card;
    
    Windows* window;/*= new First;
    window->Screen(display, entities,texts);*/
    window = new Second;
    window->Screen(display,entities,texts);
    window = new Third;
    window->Screen(display,entities,texts);

}

//ZAMIENIC TEXT NA SHARED POINTER bo nie przekazuje wektora do nastepnej funkcji
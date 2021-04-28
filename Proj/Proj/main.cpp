#include "Entity.h"
#include "Player.h"
#include "Dealer.h"

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

class Card : sf::RectangleShape {

public:
    Card(sf::Vector2f size) : RectangleShape(size)
    {

        //this->setTextureRect
    }
};

class Deck {
    vector<Card> vec_cards;
public:

};

class Windows{
    virtual void Screen2() = 0;
public:
    Windows() {};
    virtual void Screen(sf::RenderWindow&, vector<Entity*>&)=0;
};

class First :public Windows{
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)override;
    virtual void Screen2() {};

private:
    vector<int> vec_values(const string&);
    vector<string> vec_names(const string& names);
    vector<Entity*> createEntities(vector<string> names, vector<int>values);
};

class Second:public Windows {
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent) override;
    virtual void Screen2() {};
};

vector<string> First::vec_names(const string& names)
{    
    string word = "";
    vector<string>vector_names;

    for (auto x : names)
    {
        if (vector_names.size() < 3)
        {
            if (x == ' ')
            {
                vector_names.push_back(word);
                word = "";
            }
            else
                word = word + x;
        }
    }
    return vector_names;
}

vector<int> First::vec_values(const string& values)
{
    string word = "";
    vector<int>vector_values;

    for (auto x : values)
    {
        if (vector_values.size() < 3)
        {
            if (x == ' ')
            {
                vector_values.push_back(stoi(word));
                word = "";
            }
            else
                word = word + x;
        }
    }
    return vector_values;
}

vector<Entity*> First::createEntities(vector<string> names, vector<int>values)
{
    int number_entities = names.size() + 1;
    vector<Entity*> vec_ent;

    if (names.size() > values.size())//if not enough values then push 0 as value.
    {
        values.push_back(0);
        values.push_back(0);
    }

    for (int i = 0; i < number_entities; i++)
    {
        if (i == 0)
        {
            Entity* ent = new Dealer();
            vec_ent.push_back(ent);
        }
        else
        {
            Entity* ent = new Player(names[i - 1], values[i - 1]);
            vec_ent.push_back(ent);
        }
    }
    return vec_ent;
}

void First::Screen(sf::RenderWindow& window,vector<Entity*>& vec_ent)
{ 
    window.setTitle("Oczko - Podaj nazwe graczy");
   
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";
    

    sf::Text txt("Podaj nazwy graczy (max 3) i potwierdz enterem:",font,24)
        ,txt_entered,txt2,txt_entered2;
    txt.setStyle(sf::Text::Bold);
    txt.setFillColor(sf::Color::White);
    txt_entered = txt2 = txt_entered2 = txt;
    txt2.setString("Podaj ilosc pieniedzy kazdego z graczy:");

    bool state = 0;
    string imiona="",values="";
    vector<string> vec_name;
    vector<int> vec_val;

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                window.close();
            }
            if (ev.type == sf::Event::TextEntered)
            {
                if (state == 0)
                {
                    if (ev.text.unicode == '\b' and !imiona.empty())
                        imiona.erase(imiona.size() - 1, 1);
                    else if (ev.text.unicode < 128)
                        imiona += (ev.text.unicode);
                }
                else
                {
                    if (ev.text.unicode == '\b' and !values.empty())
                        values.erase(values.size() - 1, 1);
                    else if (ev.text.unicode < 128)
                        values += (ev.text.unicode);
                }
            }
         
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Enter)
                {
                    if (state == 0&& !imiona.empty())                    
                    {
                        vec_name = vec_names(imiona);
                        state = 1;
                      
                        //window.setActive(false);//nie dziala
                    }
                    
                    if (state == 1 && !values.empty())
                    {
                        vec_val = vec_values(values);
                        vec_ent = createEntities(vec_name,vec_val);
                        return;
                    }
                }
            }
        }

        
        txt_entered.setString(imiona);
        txt_entered.setPosition(0, 25);

        txt2.setPosition(0, 50);

        txt_entered2.setString(values);
        txt_entered2.setPosition(0, 75);

        window.clear();
        window.draw(txt);
        window.draw(txt_entered);
        if (state == 1)
        {
            window.draw(txt2);
            window.draw(txt_entered2);
        }
        window.display();
    }
}

//zamienic z entity
void Second::Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)
{
    
    window.setTitle("Oczko - Daj Pieniadze");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";

    string playerName = "edek";
    
    sf::Text name(playerName, font, 24),dealer("Dealer",font,24);
    name.setPosition(50, 565);
    dealer.setOrigin(36.0f, 9.0f);
    dealer.setPosition(400,10);

    sf::Vector2f card_size(60.0f, 90.0f);
    sf::RectangleShape card(card_size);
    vector<sf::RectangleShape> cards;

    for(int j=0;j<4;j++)
    for (int i = 0; i < 3; i++)
    {
        cards.push_back(card);
        cards[i+j*3].setFillColor(sf::Color::Red);
        cards[i+j*3].setPosition(10+i*70, 475-j*100);//x + 3 karty oddalone od sb o 70, y - 4 karty oddalone od sb o 100 
    }

    int money = 5;
    sf::Text moneyText(to_string(money) + "$", font, 24);
    moneyText.setPosition(150, 565);

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

                }
            }
            if (sf::Event::MouseWheelScrolled)
            {
                if (ev.mouseWheelScroll.delta == 1)//UP
                {                 
                    money++;
                    cout << "Money: " << money << endl;
                    moneyText.setString(to_string(money) + "$");
                
                }
                if (ev.mouseWheelScroll.delta == -1 and money > 0)//DOWN
                {
                   
                    money--;
                    cout << "Money: " << money << endl;
                    moneyText.setString(to_string(money)+"$");
                }
            }
        }



        window.clear(sf::Color(0, 100, 50, 250));
        window.draw(name);
        for(int i=0;i<11;i++)
            window.draw(cards[i]);
        window.draw(moneyText);
        window.draw(dealer);
        window.display();
    }
}


int main()
{
    sf::RenderWindow display(sf::VideoMode(800, 600), "", sf::Style::Close | sf::Style::Titlebar);
    vector<Entity*> entities;
    Windows* window= new First;
    window->Screen(display, entities);
   /* window = new Second;
    window->Screen(display);
    Entity* ent=new Player("arek",25);*/
 

}
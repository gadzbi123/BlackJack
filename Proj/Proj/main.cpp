#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>


using namespace std;

class Entity
{
public:
    string name;
    //virtual void make_a_bet();
};

class Player:public Entity
{
    //Saldo saldo;
    int money;
    int bet;
public:
    //void make_a_bet();
};

class Dealer :public Entity
{

};

/*vector<Entity>*/void createEntities()
{

}

class Windows{
public:
    Windows() {};
    virtual vector<string> Screen(sf::RenderWindow&)=0;
    virtual void Screen2() = 0;
};

class First :public Windows{
public:
    vector<string> Screen(sf::RenderWindow&) override;
    virtual void Screen2() {};

private:
    vector<string> vec_names(const string& names);
};

class Second:public Windows {
    vector<string> Screen(sf::RenderWindow&) override;
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

vector<string> First::Screen(sf::RenderWindow& window)
{ 
    window.setTitle("Oczko - Podaj nazwe graczy");
   
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";
    

    sf::Text txt,txt_entered;
    txt.setFont(font);
    txt.setString("Podaj nazwy graczy (max 3) i potwierdz enterem: \n");
    txt.setStyle(sf::Text::Bold);
    txt.setFillColor(sf::Color::White);
    txt.setCharacterSize(24);
    txt_entered = txt;

    string imiona;

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
            if (ev.type == sf::Event::TextEntered)
            {
                if (ev.text.unicode<128)
                {
                    imiona += (ev.text.unicode);
                }
            }
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Enter)
                {
                    vector<string> tab_name = vec_names(imiona);
                    window.setActive(false);//nie dziala
                    return tab_name;
                }
            }
        }

        
        txt_entered.setString(imiona);
        txt_entered.setPosition(0, 25);

        window.clear();
        window.draw(txt);
        window.draw(txt_entered);
        window.display();
    }
}



vector<string> Second::Screen(sf::RenderWindow& window)
{
    vector<string> x;
    x.clear();
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


    return x;
}


int main()
{
    sf::RenderWindow display(sf::VideoMode(800, 600), "", sf::Style::Close | sf::Style::Titlebar);
    Windows* window;/*= new First;
    window->Screen(display);
    delete window;*/
    window = new Second;
    window->Screen(display);
}
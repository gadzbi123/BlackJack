#include <iostream>
#include <SFML\Graphics.hpp>


using namespace std;

class Entity
{
public:
    
};

class Player:public Entity
{

};

class Dealer :public Entity
{

};

string* tab_names(const string& names,int& count)
{    
    string word = "";
    string* names_tab=nullptr;
    count = 0;
    for (auto x : names)
    {
        if (x == ' ')
        {
            names_tab = new string(word);
            count++;
            word = "";
        }
        else 
            word = word + x; 
    }    
    return names_tab;
}

int main()
{ 
    sf::RenderWindow window(sf::VideoMode(800, 600), "Oczko: podaj graczy", sf::Style::Close | sf::Style::Titlebar );
   
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
    int liczba_imion;

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
                    string* tab_imion = tab_names(imiona, liczba_imion);
                    window.setActive(false);//nie dziala
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
    return 0;
}


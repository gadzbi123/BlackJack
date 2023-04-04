#include "Zero.h"

void Zero::load_from_file(vector<string>& vec_str, vector<int>& vec_int)
{
    string line, name, cash;

    ifstream file("Salda.txt");
    if (!file.is_open())
        cout << "Can't open Salda.txt";
    else
    {
        while (getline(file, line))
        {
            name = line;
            if (name == "\n")
                break;
            getline(file, line);
            cash = line;

            vec_str.push_back(name);
            vec_int.push_back(stoi(cash));

        }
    }
    file.close();

}

void Zero::methodY(vector<Entity*>& vec_ent)
{
    vector<int> v;
    vector<string> n;
    load_from_file(n, v);
    vec_ent = createEntities(n, v);
    return;
}

void Zero::Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)
{
    window.setTitle("BlackJack - New Game/Resume");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";

    sf::Text txt("Do u want to resume previous game? y/n", font, 24);
    txt.setPosition(200, 250);
    txt.setFillColor(sf::Color::White);


    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
            {
                window.close();
            }
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Y)
                {
                    methodY(vec_ent);
                    return;
                }
                if (ev.key.code == sf::Keyboard::N)
                    return;
            }

        }
        window.clear();
        window.draw(txt);
        window.display();
    }
}
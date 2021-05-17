#include "First.h"
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

    if (vector_names.size() < 3)
        vector_names.push_back(word);

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

    if (vector_values.size() < 3)
        vector_values.push_back(stoi(word));

    return vector_values;
}



void First::Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)
{
    window.setTitle("BlackJack - List players");

    vector<sf::Text> vec_txt;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";


    sf::Text txt("", font, 24); // 0- list the, 1- set a total, 2-names,3-values
    

    txt.setString("List the names of the players (max 3) and confirm with enter:");
    txt.setFillColor(sf::Color::White);
    vec_txt.push_back(txt);

    txt.setString("Set a total money for every player:");
    txt.setPosition(0, 50);
    vec_txt.push_back(txt);

    txt.setString("");
    txt.setPosition(0, 25);
    vec_txt.push_back(txt);

    txt.setPosition(0, 75);
    vec_txt.push_back(txt);

    bool state = 0;
    string imiona = "", values = "";
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
                    if (state == 0 && !imiona.empty())
                    {
                        vec_name = vec_names(imiona);
                        state = 1;

                        //window.setActive(false);//nie dziala
                    }

                    if (state == 1 && !values.empty())
                    {
                        vec_val = vec_values(values);
                        vec_ent = createEntities(vec_name, vec_val);
                        cout << vec_name.size() << " " << vec_val.size();
                        return;
                    }
                }
            }
        }


        vec_txt[2].setString(imiona);
        vec_txt[3].setString(values);

        window.clear();
        window.draw(vec_txt[0]);
        window.draw(vec_txt[2]);

        if (state == 1)
        {
            window.draw(vec_txt[1]);
            window.draw(vec_txt[3]);

        }
        window.display();
    }
}
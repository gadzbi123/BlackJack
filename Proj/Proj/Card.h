#pragma once
#include "Entity.h"
class Card {


    sf::Texture Texture;
    sf::Vector2u TextureSize;
    sf::Vector2i TextureMember;
    string Name;

    vector<string> cards_created;
public:
    sf::RectangleShape Shape;
    Card() : Name("")
    {
        sf::Vector2f x(43.0f, 65.0f);
        Shape.setSize(x);


    }
    vector<string> vec_name_cards();
    string get_name() { return this->Name; }
    bool is_card();
    void random();
    void random(string);
    sf::RectangleShape get_Shape();

};
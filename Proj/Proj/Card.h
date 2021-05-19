#pragma once
#include "Entity.h"
class Card {
    //texture for a card
    sf::Texture Texture;
    //size of a texture
    sf::Vector2u TextureSize;
    //member in the texture
    sf::Vector2i TextureMember;
    string Name;

    vector<string> cards_created;
public:
    sf::RectangleShape Shape;
public:
    Card() : Name("")
    {
        sf::Vector2f x(43.0f, 65.0f);
        Shape.setSize(x);
    }
    //all cards that can be created
    vector<string> vec_name_cards();
    string get_name() { return this->Name; }
    //checks if card is possible to be created
    bool is_card();
    //creates a random shown card
    void random();
    //creates a random card that is not visible to a player
    void random(string turned);
    sf::RectangleShape get_Shape();

};
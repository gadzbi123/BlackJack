#pragma once
#include "Entity.h"
#include "Dealer.h"
#include "Player.h"
class Windows {
public:
    Windows() {};
    virtual void Screen(sf::RenderWindow&, vector<Entity*>&) = 0;
protected:
    vector<Entity*> createEntities(vector<string> names, vector<int>values);

};

#pragma once
#include "Entity.h"
class Windows {
public:
    Windows() {};
    virtual void Screen(sf::RenderWindow&, vector<Entity*>&) = 0;
};

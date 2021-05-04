#pragma once
#include "Entity.h"
class Windows {
    virtual void Screen2() = 0;
public:
    Windows() {};
    virtual void Screen(sf::RenderWindow&, vector<Entity*>&) = 0;
};

#pragma once
#include "Windows.h"
class Second :public Windows {
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent) override;

};

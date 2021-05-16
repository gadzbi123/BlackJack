#pragma once
#include "Windows.h"
#include "Card.h"

class Third : public Windows {
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent) override;
    int hit_or_stand(int casey);
    int calculate_card(string x);

};


#pragma once
#include "Windows.h"
#include "Player.h"
#include "Dealer.h"

//Screen lets player creates players and amount of money for each
class First :public Windows {
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)override;
private:
    //creates a vector of money to later create entities
    vector<int> vec_values(const string&);
    //creates a vector of names to later create entities
    vector<string> vec_names(const string& names);
};



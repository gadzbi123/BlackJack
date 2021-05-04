#pragma once
#include "Windows.h"
#include "Player.h"
#include "Dealer.h"
class First :public Windows {
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)override;
    virtual void Screen2() {};
    //vector<Entity*> createEntities(vector<string> names, vector<int>values);


private:
    vector<int> vec_values(const string&);
    vector<string> vec_names(const string& names);
};

vector<Entity*> createEntities(vector<string> names, vector<int>values);


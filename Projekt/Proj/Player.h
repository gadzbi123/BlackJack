#pragma once
#include "Entity.h"

class Player :public Entity
{
private:
    int money;
    int bet;
public:
    Player(string name) : Entity(name) { money = 0; bet = 0; }
    Player(string name,int _money) : Entity(name), money(_money), bet(0) {}
    bool set_money(int);
    int get_money();
    void set_bet(int);
    int get_bet();
};



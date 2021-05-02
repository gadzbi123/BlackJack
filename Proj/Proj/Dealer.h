#pragma once
#include "Entity.h"
class Dealer :public Entity
{
private:
    int income;
public:
    Dealer() : Entity("Dealer"), income(0) {}
    Dealer(int value) : Entity("Dealer"), income(value) {}
    int calculate_income(vector<Entity*> ent);
    int get_money();
    bool set_money(int);
    virtual void set_bet(int) {};

};


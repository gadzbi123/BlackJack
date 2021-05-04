#pragma once
#include "Entity.h"
class Dealer :public Entity
{
private:
    int income;

    virtual int get_bet() { return 0; }
    virtual void set_bet(int) {};
public:
    Dealer() : Entity("Dealer"), income(0) {}
    Dealer(int value) : Entity("Dealer"), income(value) {}
    int calculate_income(vector<Entity*> ent);
    int get_money();
    bool set_money(int);
 

};


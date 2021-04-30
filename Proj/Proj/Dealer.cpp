#include "Dealer.h"

int Dealer::calculate_income(vector<Entity*> ent)
{
    int _income=0;

    for (int i = 1; i < ent.size(); i++)
    {
        _income += ent[i]->get_money();
    }

    return _income;
}

int Dealer::get_money()
{
    return this->income;
}

bool Dealer::set_money(int value)
{
	this->income = value;
	return true;
}

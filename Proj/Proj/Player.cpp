#include "Player.h"

bool Player::set_money(int value)
{
	if (value >= 0)
	{
		this->money = value;
		return true;
	}
	else
		return false;
}

int Player::get_money()
{
	return this->money;
}

void Player::set_bet(int v)
{
	this->bet = v;
}

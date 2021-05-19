#include "History.h"


void History::add(string name, int prize)
{
    for (int i = 0; i < names.size(); i++)
        if (names[i] == name)
            return;
    
    names.push_back(name);
    prize_pool.push_back(prize);
}

void History::clear()
{
    names.clear();
    prize_pool.clear();
}

string History::result()
{
    string output = "Winner:\n";
    for (int i = 0; i < names.size(); i++)
    {
        if (prize_pool[i] > 0)
        {
            output += names[i];
            output += " with ";
            output += (to_string(prize_pool[i]) + "$\n");
        }
    }

    output += "Loser:\n";
    for (int i = 0; i < names.size(); i++)
    {
        if (prize_pool[i] < 0)
        {
            output += names[i];
            output += " with ";
            output += (to_string(-prize_pool[i]) + "$ lost\n");
        }
    }

    output += "Draw:\n";
    for (int i = 0; i < names.size(); i++)
    {
        if (prize_pool[i] == 0)
        {
            output += names[i];
            output += "\n";
        }
    }
    return output;
}

bool History::empty()
{
    if (names.empty())
        return true;
    else
        return false;
}

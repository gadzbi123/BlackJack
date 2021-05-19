#include "Windows.h"

vector<Entity*> Windows::createEntities(vector<string> names, vector<int>values)
{
    int number_entities = names.size() + 1;
    vector<Entity*> vec_ent;

    while (names.size() != values.size())//if not enough values then push 0 as value.
    {
        values.push_back(0);
    }

    for (int i = 0; i < number_entities; i++)
    {
        if (i == 0)
        {
            Entity* ent = new Dealer();
            vec_ent.push_back(ent);
        }
        else
        {
            Entity* ent = new Player(names[i - 1], values[i - 1]);
            vec_ent.push_back(ent);
        }
    }
    return vec_ent;
}
#pragma once
#include "Windows.h"
class Zero : public Windows
{
private:
    void load_from_file(vector<string>& vec_str, vector<int>& vec_int);
    void methodY(vector<Entity*>& vec_ent);
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent);
};

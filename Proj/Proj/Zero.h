#pragma once
#include "Windows.h"

//Screen checks if a player wants to play a new game or resume previos one
class Zero : public Windows
{
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent);
private:
    //Loads money and names from the file
    void load_from_file(vector<string>& vec_str, vector<int>& vec_int);
    //performs a method when player presses Y on keyboard - reads from file the previous names
    void methodY(vector<Entity*>& vec_ent);

};

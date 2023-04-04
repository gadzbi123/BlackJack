#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class History
{
    vector<string> names;
    vector<int> prize_pool;
public:
    //Adds a History of one player into the Object
    void add(string name, int prize);
    //Clears the history completly
    void clear();
    //Returns the string of result of history
    string result();
    //Checks if history is empty
    bool empty();
};

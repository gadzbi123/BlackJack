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
    void add(string name, int prize);
    void clear();
    string result();
    bool empty();
};

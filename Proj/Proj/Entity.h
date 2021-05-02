#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <memory>
#include <SFML\Graphics.hpp>

using namespace std;

class Entity
{
protected:
    string name;
    //virtual void make_a_bet();
public:
    Entity() {};
    Entity(string _name) :name(_name) {}
    string get_name() { return this->name; }
    virtual int get_money() = 0;
    virtual bool set_money(int) = 0;
    virtual void set_bet(int) = 0;


};

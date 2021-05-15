#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <memory>
#include <Windows.h>
#include <SFML\Graphics.hpp>

using namespace std;

class Entity
{
protected:
    string name;
    int points;
    int cards_shown;
public:
    Entity(): points(0),cards_shown(2) {};
    Entity(string _name) :name(_name),points(0),cards_shown(2) {}
    string get_name() { return this->name; }
    int get_points() { return this->points; }
    void add_points(int p) { this->points+=p; }
    void reset_points_cards() { this->points = 0; this->cards_shown = 2; }
    void increm_cards_shown() { this->cards_shown++; }
    int get_cards_shown() { return this->cards_shown; }
    virtual int get_money() = 0;
    virtual bool set_money(int) = 0;
    virtual void set_bet(int) = 0;
    virtual int get_bet() = 0;


};

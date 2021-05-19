#pragma once
#include "Windows.h"
#include "Card.h"

//Screen in which the cards are shown
class Third : public Windows {
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent) override;
private:
    //makes a decision to hit a card or stand
    int hit_or_stand(int casey);
    //calculates the points from a card
    int calculate_card(string x);
    //saves the entities to a file "Salda.txt"
    void save_to_file(vector<Entity*>& vec_ent);
    //performs a action hit by a player
    void hitButton(vector<Entity*>& vec_ent, int current_player, vector<Card>& cards);
    //performs a doubledown action by a player
    void doubledownButton(int& current_player, vector<Entity*>& vec_ent);
    //calculates 2 cards shown at the start for each entity
    void calculate_start_cards(vector<Entity*>& vec_ent,vector<Card> cards);
};


#pragma once
#include "Windows.h"
#include "Card.h"

class Third : public Windows {
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent) override;
private:
    int hit_or_stand(int casey);
    int calculate_card(string x);
    void save_to_file(vector<Entity*>& vec_ent);
    void hitButton(vector<Entity*>& vec_ent, int current_player, vector<Card>& cards);
    void doubledownButton(int& current_player, vector<Entity*>& vec_ent);
    void calculate_start_cards(vector<Entity*>& vec_ent,vector<Card> cards);
};


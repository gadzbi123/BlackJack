#pragma once
#include "Windows.h"
class Second :public Windows {
public:
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent) override;
private:
    void createVec_txt(const vector<Entity*>& vec_ent, vector<sf::Text>& vec_txt);

};

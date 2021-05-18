#include "Card.h"

vector<string> Card::vec_name_cards()
{
    vector<string> names_of_cards;

    //loop for numbers
    for (int i = 2; i < 11; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
                names_of_cards.push_back(to_string(i) + "h"); //hearts
            if (j == 1)
                names_of_cards.push_back(to_string(i) + "s"); //spades
            if (j == 2)
                names_of_cards.push_back(to_string(i) + "c"); //clubs
            if (j == 3)
                names_of_cards.push_back(to_string(i) + "d"); //diamonds

        }
    }

    //loop for figures
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)//Jacks
            {
                if (j == 0)
                    names_of_cards.push_back("Jh"); //hearts
                if (j == 1)
                    names_of_cards.push_back("Js"); //spades
                if (j == 2)
                    names_of_cards.push_back("Jc"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Jd"); //diamonds
            }

            if (i == 1)//Queens
            {
                if (j == 0)
                    names_of_cards.push_back("Qh"); //hearts
                if (j == 1)
                    names_of_cards.push_back("Qs"); //spades
                if (j == 2)
                    names_of_cards.push_back("Qc"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Qd"); //diamonds
            }

            if (i == 2)//Kings
            {
                if (j == 0)
                    names_of_cards.push_back("Kh"); //hearts
                if (j == 1)
                    names_of_cards.push_back("Ks"); //spades
                if (j == 2)
                    names_of_cards.push_back("Kc"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Kd"); //diamonds
            }

            if (i == 3)//Aces
            {
                if (j == 0)
                    names_of_cards.push_back("Ah"); //hearts
                if (j == 1)
                    names_of_cards.push_back("As"); //spades
                if (j == 2)
                    names_of_cards.push_back("Ac"); //clubs
                if (j == 3)
                    names_of_cards.push_back("Ad"); //diamonds
            }
        }
    }
    return names_of_cards;
}

void Card::random()
{
start:
    string _name = "";
    int x, y;

    std::default_random_engine los;
    los.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, 12), distr2(0, 3);

    x = distr(los);
    if (x < 9)
        _name += to_string(x + 2);
    if (x == 9)
        _name += "J";
    if (x == 10)
        _name += "Q";
    if (x == 11)
        _name += "K";
    if (x == 12)
        _name += "A";

    y = distr2(los);
    if (y == 0)
        _name += "s";
    if (y == 1)
        _name += "d";
    if (y == 2)
        _name += "c";
    if (y == 3)
        _name += "h";

    for (int i = 0; i < cards_created.size(); i++)
        if (cards_created[i] == _name)
            goto start;

    cards_created.push_back(_name);

    this->Texture.loadFromFile("texture/karty.png");
    this->Shape.setTexture(&Texture);

    this->TextureSize = Texture.getSize();
    TextureSize.x /= 13;
    TextureSize.y /= 4;
    Shape.setTextureRect(sf::IntRect(TextureSize.x * x, TextureSize.y * y, TextureSize.x, TextureSize.y));

    //cout << _name;
    this->Name = _name;
}

void Card::random(string s)
{
    if (s == "Turned")
    {        
    start:
        string _name = "";
        int x, y;

        std::default_random_engine los;
        los.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> distr(0, 12), distr2(0, 3);

        x = distr(los);
        if (x < 9)
            _name += to_string(x + 2);
        if (x == 9)
            _name += "J";
        if (x == 10)
            _name += "Q";
        if (x == 11)
            _name += "K";
        if (x == 12)
            _name += "A";

        y = distr2(los);
        if (y == 0)
            _name += "s";
        if (y == 1)
            _name += "d";
        if (y == 2)
            _name += "c";
        if (y == 3)
            _name += "h";

        for (int i = 0; i < cards_created.size(); i++)
            if (cards_created[i] == _name)
                goto start;

        this->cards_created.push_back(_name);
        this->TextureMember = sf::Vector2i(x, y);

        this->Texture.loadFromFile("texture/karty_back.png");
        this->Shape.setTexture(&Texture);

        TextureSize = Texture.getSize();
        TextureSize.x /= 2;
        TextureSize.y /= 1;
        Shape.setTextureRect(sf::IntRect(TextureSize.x * y % 2, TextureSize.y * 0, TextureSize.x, TextureSize.y));

        //cout << _name;
        this->Name = _name;
    }
}

sf::RectangleShape Card::get_Shape()
{
    return this->Shape;
}

bool Card::is_card()
{
    vector<string> cards = vec_name_cards();
    for (int i = 0; i < cards.size(); i++)
    {
        if (this->Name == cards[i])
            return true;
    }
    return false;
}
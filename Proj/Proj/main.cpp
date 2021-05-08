#include "Entity.h"
#include "Player.h"
#include "Dealer.h"
#include "Windows.h"
#include "First.h"
#include "Second.h"

vector<string> cards_created;

vector<string> vec_name_cards()
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
                if(j == 0)
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

class Calculate
{
    vector<int> points;
public:
    Calculate(vector<Entity*> vec_ent) 
    { 
        for(int i=0;i<vec_ent.size();i++)
            points.push_back(0);
    }
    void add(int ent_number)
    {

    }
};

class Card {

    
    sf::Texture Texture;
    sf::Vector2u TextureSize;
    string Name;
public:
    sf::RectangleShape Shape;
    Card(): Name("")
    {
        sf::Vector2f x(43.0f, 65.0f);
        Shape.setSize(x);

        Texture.loadFromFile("texture/karty.png");
        this->Shape.setTexture(&Texture);

        TextureSize = Texture.getSize();
        TextureSize.x /= 13;
        TextureSize.y /= 4;

    }
    
    string get_name() { return this->Name; }
    bool is_card();
    void random();
    sf::RectangleShape get_Shape();
   
};

void Card::random()
{
start:  
    string _name="";
    int x, y;

    std::default_random_engine los;
    los.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0,12),distr2(0,3);

    x = distr(los);
    if (x < 9)
        _name += to_string(x+2);
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
    Shape.setTextureRect(sf::IntRect(TextureSize.x * x, TextureSize.y * y, TextureSize.x, TextureSize.y));

    cout << _name;

    this->Name = _name;
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

class Third : public Windows {
    void Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent) override;
    virtual void Screen2() {};

};

int calculate_card(string x)
{
    int value = 0;

    if (x[0] > '2' and x[0] < '9')
        value = x[0]-48;
    if (x[0] == '1')
        value = 10;
    if (x[0] == 'J')
        value = 10;
    if (x[0] == 'Q')
        value = 10;
    if (x[0] == 'K')
        value = 10;
    if (x[0] == 'A')
        value = 11;

    return value;
}

void Third::Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)
{    
    window.setTitle("BlackJack - Show Cards");

    vector<sf::Text> vec_txt; //0 - Info, 1 - dealer, 2/4/6 -> name, 3/5/7 -> bet

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";

    //Info at start
    sf::Text InfoText("Press H to hit\nPress D to double-down\nPress S to stand\n", font, 24);
    InfoText.setOrigin(121, 25);
    InfoText.setPosition(400, 200);
    vec_txt.push_back(InfoText);

    //Dealer text
    sf::Text dealer("Dealer", font, 24);
    dealer.setOrigin(36.0f, 9.0f);
    dealer.setPosition(400, 10);
    vec_txt.push_back(dealer);

    sf::Text nameText;
    sf::Text moneyText;

    for (int i = 0; i < vec_ent.size() - 1; i++)
    {
        nameText.setString(vec_ent[i + 1]->get_name());
        nameText.setFont(font);
        nameText.setCharacterSize(24);
        nameText.setPosition(80 + i * 260, 565);
        vec_txt.push_back(nameText);

        moneyText.setString(to_string(vec_ent[i + 1]->get_bet()) + "$");
        moneyText.setFont(font);
        moneyText.setCharacterSize(24);
        moneyText.setPosition(180 + i * 260, 565);
        vec_txt.push_back(moneyText);
    }
    
    vector<Card> cards; 
    Card card;
    //Calculate calc(vec_ent);
  
    for (int k = 0; k < vec_ent.size() - 1; k++)
        for (int j = 0; j < 4; j++)
            for (int i = 0; i < 3; i++)
            {
                if (j == 3 and i == 2)
                    break;
     
                card.random();
                card.Shape.setPosition(80 + i * 50 + k * 250, 500 - j * 75);//x + 3 karty oddalone od sb o 70, y - 4 karty oddalone od sb o 100 
                cards.push_back(card);

            }

    int current_player = 1;
    int current_points = 0;

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Enter)
                {
                    return;
                }

                if (ev.key.code == sf::Keyboard::H)
                {
                    if(current_player < 4)
                        vec_ent[current_player]->increm_cards_shown();
          
                }

                if (ev.key.code == sf::Keyboard::D)
                {
                    if (current_player < 4) 
                    {
                        vec_ent[current_player]->increm_cards_shown();
                        vec_ent[current_player]->set_bet(2 * vec_ent[current_player]->get_bet());
                        vec_txt[1 + 2 * current_player].setString(to_string(vec_ent[current_player]->get_bet())+"$");
                        current_player++;
                    }
                }

                if (ev.key.code == sf::Keyboard::S)
                {
                    current_player++;
                }

            }
        }


        window.clear(sf::Color(0, 100, 50, 250));
        
        for (int i = 0; i < vec_txt.size(); i++)
            window.draw(vec_txt[i]);
        

        //Start cards
        for(int j=0;j<vec_ent.size()-1;j++)
            for (int i = 0; i < 2; i++)
            {
                window.draw(cards[i + j * 11].get_Shape());
                if (current_player == j + 1)
                    current_points=+calculate_card(cards[i + j * 11].get_name());/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            }
        //Additional cards
        for(int j=1;j<vec_ent.size();j++)
            for (int i = 2; i < vec_ent[j]->get_cards_shown(); i++)
            {
                window.draw(cards[i + (j - 1) * 11].get_Shape());
                cards[i + (j - 1) * 11].get_name();
            }

        window.display();
    }
}

int main()
{
    sf::RenderWindow display(sf::VideoMode(800, 600), "", sf::Style::Close | sf::Style::Titlebar);
    vector<Entity*> entities;

    vector<int> v;
    vector<string> n;
    for(int i = 1 ; i < 4; i++)
        n.push_back("name+"+to_string(i));
    for (int i = 1; i < 4; i++)
        v.push_back(10*i);

    entities = createEntities(n, v);

    for (int i = 1; i < 4; i++)
        entities[i]->set_bet(2 + i);

    Card card;
    
    Windows* window;/*= new First;
    window->Screen(display, entities);
    window = new Second;
    window->Screen(display,entities);*/
    window = new Third;
    window->Screen(display,entities);

}

//gdy ustawiam bet to zmniejszac money
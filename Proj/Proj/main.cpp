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
    int hit_or_stand(int casey);

};

int calculate_card(string x)
{
    int value = 0;

    if (x[0] >= '2' and x[0] <= '9')
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

int Third::hit_or_stand(int casey)
{
    std::default_random_engine los;
    los.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(0, 100);

    int x = distr(los);

    if (casey == 1)
    {
        if (x >= 66)
            return 1;
        else return -1;
    }

    if (casey == 2)
    {
        if (x >= 66)
            return -1;
        else return 1;
    }

    return 0;

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

    //Create cards visual for dealer
    for (int i = 0; i < 11; i++)
    {
        card.random();
        card.Shape.setPosition(130 + i * 50, 50);
        cards.push_back(card);
    }

    //Create cards visual for players
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

    //Calculate start cards for players and dealer
    for (int j = 0; j < vec_ent.size(); j++)
    {      
        for (int i = 0; i < 2; i++)
        {
            int card_value = calculate_card(cards[i + j * 11].get_name());
            if (card_value == 11 and current_points > 10)
                card_value = 1;
            current_points += card_value;
        }
        vec_ent[j]->add_points(current_points);
        current_points = 0;
    }

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
                    if (current_player < vec_ent.size())
                    {
                        vec_ent[current_player]->increm_cards_shown();
                        int shown = vec_ent[current_player]->get_cards_shown();
                        current_points = calculate_card(cards[(shown - 1)+(current_player)*11].get_name());

                        if (current_points == 11 and vec_ent[current_player]->get_points() > 10)
                            current_points = 1;

                        vec_ent[current_player]->add_points(current_points);
                        cout<<current_player<<" "<<vec_ent[current_player]->get_points()<<endl;
                        
                        current_points = 0;

                        if (vec_ent[current_player]->get_points() > 21)
                        {
                            vec_txt[2 * current_player].setFillColor(sf::Color::Red);
                            cout << "bust";
                            current_player++;
                            
                        }
                    }
                }

                if (ev.key.code == sf::Keyboard::D)
                {
                    if (current_player < vec_ent.size()) 
                    {
                        vec_ent[current_player]->increm_cards_shown();
                        vec_ent[current_player]->set_bet(2 * vec_ent[current_player]->get_bet()); //odjąć od money gracza
                        vec_txt[1 + 2 * current_player].setString(to_string(vec_ent[current_player]->get_bet())+"$");
                        current_player++;
                    }
                }

                if (ev.key.code == sf::Keyboard::S)
                {
                    if (current_player < vec_ent.size())
                        current_player++;
                }

            }
        }

        //Dealer's turn
        if (current_player == vec_ent.size())    
        {
          /*  for (int i = 0; i < vec_ent.size(); i++)
                cout << "points_player" << i << "=" << vec_ent[i]->get_points() << endl;*/
            int choice = 0;//1=hit, -1=stand, 0=bust
            int income = 0, temp = 0;

            if (vec_ent[0]->get_points() > 18 and vec_ent[0]->get_points() <= 21)
                choice = -1;

            if (vec_ent[0]->get_points()>14 and vec_ent[0]->get_points()<=18)
                choice = hit_or_stand(1);

            if (vec_ent[0]->get_points() <= 14 and vec_ent[0]->get_points() >= 11);
                choice = hit_or_stand(2);

            if (vec_ent[0]->get_points() < 11);
                choice = 1;

            if (vec_ent[0]->get_points() > 21)
            {
                vec_txt[1].setFillColor(sf::Color::Red);
                cout << "bust";
          

                for (int i = 1; i < vec_ent.size(); i++)
                {
                    int cash = vec_ent[i]->get_money();
                    int bet = vec_ent[i]->get_bet();
                    vec_ent[i]->set_money(cash + 2 * bet);
                    income -= bet;
                }

                temp = vec_ent[0]->get_money();
                vec_ent[0]->set_money(temp + income);
                choice = 0;
                current_player++;
            }

            //hit
            if (choice == 1)
            {
                vec_ent[0]->increm_cards_shown();
                int shown = vec_ent[0]->get_cards_shown();
                current_points = calculate_card(cards[(shown - 1)].get_name());

                if (current_points == 11 and vec_ent[current_player]->get_points() > 10)
                    current_points = 1;

                vec_ent[0]->add_points(current_points);
                current_points = 0;
                Sleep(1000);
            }

            //stand
            if (choice == -1)          
            if (vec_ent[0]->get_points() <= 21)
                for (int i = 1; i < vec_ent.size(); i++)
                {
                    if (vec_ent[0]->get_points() > vec_ent[i]->get_points())
                    {
                        temp = vec_ent[0]->get_money();
                        vec_ent[0]->set_money(temp + vec_ent[i]->get_bet());
                    }

                    if (vec_ent[0]->get_points() == vec_ent[i]->get_points())
                    {
                        temp = vec_ent[i]->get_money();
                        vec_ent[i]->set_money(temp + vec_ent[i]->get_bet());
                    }

                    if (vec_ent[0]->get_points() < vec_ent[i]->get_points())
                    {
                        temp = vec_ent[0]->get_money();
                        vec_ent[0]->set_money(temp - vec_ent[i]->get_bet());

                        temp = vec_ent[i]->get_money();
                        vec_ent[i]->set_money(temp + vec_ent[i]->get_bet());

                    }
                }

            //reset
            vec_ent[0]->reset_points_cards();
            for (int i = 1; i < vec_ent.size(); i++)
            {
                vec_ent[i]->set_bet(0);
                vec_ent[i]->reset_points_cards();
            }
        }

        window.clear(sf::Color(0, 100, 50, 250));
        
        for (int i = 0; i < vec_txt.size(); i++)
            window.draw(vec_txt[i]);
       
        //Start cards for players and dealer
        for(int j=0;j<vec_ent.size();j++)
            for (int i = 0; i < 2; i++)
            {
                window.draw(cards[i + (j) * 11].get_Shape());
            }

        //Additional cards for players
        for(int j=0;j<vec_ent.size();j++)
            for (int i = 2; i < vec_ent[j]->get_cards_shown(); i++)
            {
                window.draw(cards[i + (j) * 11].get_Shape());
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
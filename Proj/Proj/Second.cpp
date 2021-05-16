#include "Second.h"

void createVec_txt(const vector<Entity*>& vec_ent, vector<shared_ptr<sf::Text>>& vec_txt)
{
    vec_txt.clear();
    //vector<sf::Text> vec_txt; //0 - Info, 1 - dealer, 2- money/income, 3-history, 4/6/8 -> name, 5/7/9 -> bet

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";

    //Info at start
    shared_ptr<sf::Text> InfoText(new sf::Text("Use scroll to set a bet\npress enter to confirm", font, 24));
    InfoText->setOrigin(121, 25);
    InfoText->setPosition(400, 270);
    vec_txt.push_back(InfoText);

    //Dealer text
    shared_ptr<sf::Text> dealer(new sf::Text("Dealer", font, 24));
    dealer->setOrigin(36.0f, 9.0f);
    dealer->setPosition(400, 10);
    vec_txt.push_back(dealer);

    //Money or income text
    string str_money_income = "Income/Money:\n";
    for (int i = 0; i < vec_ent.size(); i++)
    {
        str_money_income += vec_ent[i]->get_name();
        str_money_income += " - ";
        str_money_income += to_string(vec_ent[i]->get_money());
        str_money_income += " $\n";
    }
    shared_ptr<sf::Text> Money_Income(new sf::Text(str_money_income, font, 16));
    Money_Income->setPosition(680, 0);
    vec_txt.push_back(Money_Income);

    //History Text
    shared_ptr<sf::Text> History(new sf::Text("History", font, 24));
    vec_txt.push_back(History);

    //Player names text
    shared_ptr<sf::Text> nameText1;
    shared_ptr<sf::Text> nameText2;
    shared_ptr<sf::Text> nameText3;

    shared_ptr<sf::Text> moneyText1;
    shared_ptr<sf::Text> moneyText2;
    shared_ptr<sf::Text> moneyText3;

    if (vec_ent.size() < 3)
    {
        nameText1 = make_shared <sf::Text>(vec_ent[1]->get_name(), font, 24);
        nameText1->setPosition(50, 565);
        vec_txt.push_back(nameText1);

        moneyText1 = make_shared<sf::Text>("5$", font, 24);
        moneyText1->setPosition(150, 565);
        vec_txt.push_back(moneyText1);
    }

    if (vec_ent.size() < 4)
    {
        nameText2=make_shared<sf::Text>(vec_ent[2]->get_name(), font, 24);
        nameText2->setPosition(50 + 265, 565);
        vec_txt.push_back(nameText2);

        moneyText2 = make_shared<sf::Text>("5$", font, 24);
        moneyText2->setPosition(150 + 265, 565);
        vec_txt.push_back(moneyText2);
    }

    if (vec_ent.size() < 5)
    {
        nameText3 = make_shared<sf::Text>(vec_ent[3]->get_name(), font, 24);
        nameText3->setPosition(50 + 530, 565);
        vec_txt.push_back(nameText3);

        moneyText3 = make_shared<sf::Text>("5$", font, 24);
        moneyText3->setPosition(150 + 530, 565);
        vec_txt.push_back(moneyText3);
    }

   /* for (int i = 0; i < vec_ent.size() - 1; i++)
    {
        nameText->setString(vec_ent[i + 1]->get_name());
        nameText->setFont(font);
        nameText->setCharacterSize(24);
        nameText->setPosition(50 + i * 265, 565);
        vec_txt.push_back(nameText);

        moneyText->setString("5$");
        moneyText->setFont(font);
        moneyText->setCharacterSize(24);
        moneyText->setPosition(150 + i * 265, 565);
        vec_txt.push_back(moneyText);
    }
  */
}


void OLDcreateVec_txt(const vector<Entity*>& vec_ent, vector<sf::Text>& vec_txt)
{
    vec_txt.clear();
    //vector<sf::Text> vec_txt; //0 - Info, 1 - dealer, 2- money/income, 3-history, 4/6/8 -> name, 5/7/9 -> bet

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";

    //Info at start
    sf::Text InfoText("Use scroll to set a bet\npress enter to confirm", font, 24);
    InfoText.setOrigin(121, 25);
    InfoText.setPosition(400, 270);
    vec_txt.push_back(InfoText);

    //Dealer text
    sf::Text dealer("Dealer", font, 24);
    dealer.setOrigin(36.0f, 9.0f);
    dealer.setPosition(400, 10);
    vec_txt.push_back(dealer);

    //Money or income text
    string str_money_income = "Income/Money:\n";
    for (int i = 0; i < vec_ent.size(); i++)
    {
        str_money_income += vec_ent[i]->get_name();
        str_money_income += " - ";
        str_money_income += to_string(vec_ent[i]->get_money());
        str_money_income += " $\n";
    }
    sf::Text Money_Income(str_money_income, font, 16);
    Money_Income.setPosition(680, 0);
    vec_txt.push_back(Money_Income);

    //History Text
    sf::Text History("History", font, 24);
    vec_txt.push_back(History);

    sf::Text nameText;
    sf::Text moneyText;

    for (int i = 0; i < vec_ent.size() - 1; i++)
    {
        nameText.setString(vec_ent[i + 1]->get_name());
        nameText.setFont(font);
        nameText.setCharacterSize(24);
        nameText.setPosition(50 + i * 265, 565);
        vec_txt.push_back(nameText);

        moneyText.setString("5$");
        moneyText.setFont(font);
        moneyText.setCharacterSize(24);
        moneyText.setPosition(150 + i * 265, 565);
        vec_txt.push_back(moneyText);
    }
}

void Second::Screen(sf::RenderWindow& window, vector<Entity*>& vec_ent)
{
    window.setTitle("BlackJack - Make a bet");

    vector<sf::Text> vec_txt;
    //vector<sf::Text> vec_txt; //0 - Info, 1 - dealer, 2- money/income, 3-history, 4/6/8 -> name, 5/7/9 -> bet

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";

    //Info at start
    sf::Text InfoText("Use scroll to set a bet\npress enter to confirm", font, 24);
    InfoText.setOrigin(121, 25);
    InfoText.setPosition(400, 270);
    vec_txt.push_back(InfoText);

    //Dealer text
    sf::Text dealer("Dealer", font, 24);
    dealer.setOrigin(36.0f, 9.0f);
    dealer.setPosition(400, 10);
    vec_txt.push_back(dealer);

    //Money or income text
    string str_money_income = "Income/Money:\n";
    for (int i = 0; i < vec_ent.size(); i++)
    {
        str_money_income += vec_ent[i]->get_name();
        str_money_income += " - ";
        str_money_income += to_string(vec_ent[i]->get_money());
        str_money_income += " $\n";
    }
    sf::Text Money_Income(str_money_income, font, 16);
    Money_Income.setPosition(680, 0);
    vec_txt.push_back(Money_Income);

    //History Text
    sf::Text History("History", font, 24);
    vec_txt.push_back(History);

    sf::Text nameText;
    sf::Text moneyText;

    for (int i = 0; i < vec_ent.size() - 1; i++)
    {
        nameText.setString(vec_ent[i + 1]->get_name());
        nameText.setFont(font);
        nameText.setCharacterSize(24);
        nameText.setPosition(80 + i * 260, 565);
        vec_txt.push_back(nameText);

        moneyText.setString("5$");
        moneyText.setFont(font);
        moneyText.setCharacterSize(24);
        moneyText.setPosition(180 + i * 260, 565);
        vec_txt.push_back(moneyText);
    }

    int bet = 5;
    int currentPlayer = 1;
    bool money_income_show = 0;
    bool history_show = 0;

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
                    if (currentPlayer < vec_ent.size())
                    {
                        //czy wystarczy pieniedzy dziala?
                        if (bet > vec_ent[currentPlayer]->get_money());
                            break;
                        vec_ent[currentPlayer]->set_bet(bet);
                        int cash = vec_ent[currentPlayer]->get_money();
                        vec_ent[currentPlayer]->set_money(cash-bet);
                        bet = 5;
                        currentPlayer++;
                    }
                    else
                    {
                        //rozdaj karty
                        return;

                    }
                }

                if (ev.key.code == sf::Keyboard::M)
                {
                    if (money_income_show == 0)
                        money_income_show = 1;
                    else
                        money_income_show = 0;
                }

                if (ev.key.code == sf::Keyboard::H)
                {
                    if (history_show == 0)
                        history_show = 1;
                    else
                        history_show = 0;
                }

            }

            if (sf::Event::MouseWheelScrolled)
            {
                if (ev.mouseWheelScroll.delta == 1)//UP
                {
                    bet++;
                    vec_txt[currentPlayer * 2 + 3].setString(to_string(bet) + "$");

                }
                if (ev.mouseWheelScroll.delta == -1 and bet > 0)//DOWN
                {
                    bet--;
                    vec_txt[currentPlayer * 2 + 3].setString(to_string(bet) + "$");
                }
            }
        }


        window.clear(sf::Color(0, 100, 50, 250));

        for (int i = 0; i < vec_txt.size(); i++)
        {
            if (i == 2 && money_income_show == 1) //show money
            {
                window.draw(vec_txt[2]);
                i++;
            }

            if (i == 2 && money_income_show == 0)//dont show money
                i++;

            if (i == 3 && history_show == 1) //show history
            {
                window.draw(vec_txt[3]);
                i++;
            }

            if (i == 3 && history_show == 0) //dont show history
                i++;

            window.draw(vec_txt[i]);
        }
        window.display();
    }
}
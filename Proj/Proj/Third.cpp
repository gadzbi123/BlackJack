#include "Third.h"

int Third::calculate_card(string x)
{
    int value = 0;

    if (x[0] >= '2' and x[0] <= '9')
        value = x[0] - 48;
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

        if (i == 0)
            nameText.setStyle(sf::Text::Underlined);
        else
            nameText.setStyle(sf::Text::Regular);

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
        if (i == 1)
            card.random("Turned");
        else
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
    int reset = 0;

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
                    if (reset == 1)
                        reset = 2;
                }

                if (ev.key.code == sf::Keyboard::H)
                {
                    if (current_player < vec_ent.size())
                    {
                        vec_ent[current_player]->increm_cards_shown();
                        int shown = vec_ent[current_player]->get_cards_shown();
                        current_points = calculate_card(cards[(shown - 1) + (current_player) * 11].get_name());

                        if (current_points == 11 and vec_ent[current_player]->get_points() > 10)
                            current_points = 1;

                        vec_ent[current_player]->add_points(current_points);
                        cout << current_player << " " << vec_ent[current_player]->get_points() << endl;

                        current_points = 0;


                    }
                }

                if (ev.key.code == sf::Keyboard::D)
                {
                    if (current_player < vec_ent.size())
                    {
                        vec_ent[current_player]->increm_cards_shown();
                        current_player++;
                        if (vec_ent[current_player]->get_money() < 2 * vec_ent[current_player]->get_bet())
                        {
                            vec_ent[current_player]->set_bet(vec_ent[current_player]->get_money());
                            vec_ent[current_player]->set_money(0);
                            vec_txt[1 + 2 * current_player].setString(to_string(vec_ent[current_player]->get_bet()) + "$");
                        }
                        else
                        {
                            vec_ent[current_player]->set_money(vec_ent[current_player]->get_money() - vec_ent[current_player]->get_bet());
                            vec_ent[current_player]->set_bet(2 * vec_ent[current_player]->get_bet());
                            vec_txt[1 + 2 * current_player].setString(to_string(vec_ent[current_player]->get_bet()) + "$");
                        }
                        vec_ent[current_player]->increm_cards_shown();
                        current_player++;
                    }
                }

                if (ev.key.code == sf::Keyboard::S)
                {
                    if (current_player < vec_ent.size())
                    {
                        vec_txt[2 * current_player].setStyle(sf::Text::Regular);
                        current_player++;

                        if (current_player < 4)
                            vec_txt[2 * current_player].setStyle(sf::Text::Underlined);
                        else
                            vec_txt[1].setStyle(sf::Text::Underlined);
                    }
                }

                //calculate
                if (current_player < vec_ent.size())
                {
                    current_points = vec_ent[current_player]->get_points();
                    if (current_points > 21)
                    {
                        vec_txt[2 * current_player].setFillColor(sf::Color::Red);
                        vec_txt[2 * current_player].setStyle(sf::Text::Regular);
                        cout << "bust\n";
                        current_player++;
                    }

                    if (current_points == 21)
                    {
                        vec_txt[2 * current_player].setFillColor(sf::Color::Yellow);
                        vec_txt[2 * current_player].setStyle(sf::Text::Regular);
                        cout << "BlackJack\n";
                        current_player++;
                    }

                    if (current_points < 21) {}
                    else
                        if (current_player < vec_ent.size())
                            vec_txt[2 * current_player].setStyle(sf::Text::Underlined);
                        else
                            vec_txt[1].setStyle(sf::Text::Underlined);
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

            if (vec_ent[0]->get_points() > 14 and vec_ent[0]->get_points() <= 18)
                choice = hit_or_stand(1);

            if (vec_ent[0]->get_points() <= 14 and vec_ent[0]->get_points() >= 12)
                choice = hit_or_stand(2);

            if (vec_ent[0]->get_points() < 12)
                choice = 1;

            if (vec_ent[0]->get_points() > 21)
                choice = 0;

            if (reset == 0)
                cout << "choice=" << choice << endl;

            if (choice == 0 and reset == 0)
            {
                vec_txt[1].setFillColor(sf::Color::Red);

                cout << "bustDealer" << endl;

                for (int i = 1; i < vec_ent.size(); i++)
                {
                    vec_txt[2 * i].setFillColor(sf::Color::White);
                    int cash = vec_ent[i]->get_money();
                    int bet = vec_ent[i]->get_bet();
                    vec_ent[i]->set_money(cash + 2 * bet);
                    income -= bet;
                }

                temp = vec_ent[0]->get_money();
                vec_ent[0]->set_money(temp + income);

                reset = 1;


            }

            //hit
            if (choice == 1 and reset == 0)
            {
                cout << "hitDealer" << endl;
                vec_ent[0]->increm_cards_shown();
                int shown = vec_ent[0]->get_cards_shown();
                current_points = calculate_card(cards[(shown - 1)].get_name());

                if (current_points == 11 and vec_ent[0]->get_points() > 10)
                    current_points = 1;

                vec_ent[0]->add_points(current_points);
                current_points = 0;



            }

            //stand
            if (choice == -1 and reset == 0)
                for (int i = 1; i < vec_ent.size(); i++)
                {
                    cout << "standDealer" << endl;
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
                    if (reset == 0)
                        reset = 1;
                }

            //reset
            if (reset > 0)
            {
                vec_txt[0].setPosition(320, 200);
                vec_txt[0].setString("Press Enter to play another round\n");

                if (reset == 2)
                {

                    vec_ent[0]->reset_points_cards();
                    vec_txt[0].setFillColor(sf::Color::White);
                    vec_txt[0].setStyle(sf::Text::Regular);
                    current_player++;

                    for (int i = 1; i < vec_ent.size(); i++)
                    {
                        vec_ent[i]->set_bet(0);
                        vec_ent[i]->reset_points_cards();
                        vec_txt[i].setFillColor(sf::Color::White);
                    }
                    return;
                }
            }
        }

        window.clear(sf::Color(0, 100, 50, 250));

        for (int i = 0; i < vec_txt.size(); i++)
            window.draw(vec_txt[i]);


        //cards shown for players and dealer
        for (int j = 0; j < vec_ent.size(); j++)
            for (int i = 0; i < vec_ent[j]->get_cards_shown(); i++)
            {
                window.draw(cards[i + (j) * 11].get_Shape());
            }

        window.display();
        if (current_player == vec_ent.size() and reset == 0)
            sf::sleep(sf::milliseconds(3000));
    }
}
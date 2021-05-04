#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<memory>
using namespace std;

sf::Text* wek_txt()
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        cout << "error";

    sf::Text* w;
    w=new sf::Text("xd1", font, 24);
    w[0].setPosition(100, 100);
    w[0].setFillColor(sf::Color::White);
    w=new sf::Text("xd2", font, 24);
    w[1].setFillColor(sf::Color::White);

    return w;

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Beginner",sf::Style::Close | sf::Style::Titlebar| sf::Style::Resize); 
    sf::RectangleShape player(sf::Vector2f(100.0f,150.0f));
    player.setPosition(400, 300);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("texture/tux_from_linux.png");
    player.setTexture(&playerTexture);

    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 3;
    textureSize.y /= 9;

    player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y*8, textureSize.x, textureSize.y));


    auto wektor_text = wek_txt();

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt)) 
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
     

            }
        }
      

        window.clear();
        for (int i = 0; i < 2; i++)
            window.draw(wektor_text[0]);
        window.draw(player);
        window.display();


    }

    return 0;
}
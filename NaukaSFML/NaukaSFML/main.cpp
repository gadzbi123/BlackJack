#include<SFML/Graphics.hpp>
#include<iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Beginner",sf::Style::Close | sf::Style::Titlebar| sf::Style::Resize); 
    sf::RectangleShape player(sf::Vector2f(100.0f,150.0f));
    player.setPosition(400, 300);
    window.setKeyRepeatEnabled(false);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("texture/tux_from_linux.png");
    player.setTexture(&playerTexture);

    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 3;
    textureSize.y /= 9;

    player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y*8, textureSize.x, textureSize.y));

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
            case sf::Event::MouseWheelScrolled:
                std::cout << "Wheel movement: " << evnt.mouseWheelScroll.delta << std::endl;
                std::cout << "mouse x: " << evnt.mouseWheelScroll.x << std::endl;
                std::cout << "mouse y: " << evnt.mouseWheelScroll.y << std::endl;
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                    printf("%c", evnt.text.unicode);
                break;

            }
        }
        window.setFramerateLimit(850);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move(-0.1f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move(0.1f, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move(0.0f, -0.1f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move(0.0f, 0.1f);
        window.clear();
        window.draw(player);
        window.display();


    }

    return 0;
}
#include<SFML/Graphics.hpp>
#include<iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Beginner",sf::Style::Close | sf::Style::Titlebar| sf::Style::Resize); 

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
            case sf::Event::Resized:
                std::cout << "New width and height: " << evnt.size.width << " " << evnt.size.height << std::endl;
                break;
            case sf::Event::MouseWheelScrolled:
                std::cout << "Wheel movement: " << evnt.mouseWheelScroll.delta << std::endl;
                std::cout << "mouse x: " << evnt.mouseWheelScroll.x << std::endl;
                std::cout << "mouse y: " << evnt.mouseWheelScroll.y << std::endl;
                break;
            case sf::Event::MouseButtonPressed:
                if (evnt.mouseButton.button == sf::Mouse::Right)
                    std::cout << "Right button pressed" << std::endl;
                if (evnt.mouseButton.button == sf::Mouse::Left)
                    std::cout << "Left button pressed" << std::endl;
                if (evnt.mouseButton.button == sf::Mouse::Middle)
                    std::cout << "Middle button pressed" << std::endl;
                break;
            case sf::Event::LostFocus:
                std::cout << "Paused" << std::endl;
                break;
            case sf::Event::GainedFocus:
                std::cout << "Resumed" << std::endl;
                break;

            }
        }
        
    }

    return 0;
}
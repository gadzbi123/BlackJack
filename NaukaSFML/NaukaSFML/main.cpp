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
            }
        }
        
    }

    return 0;
}
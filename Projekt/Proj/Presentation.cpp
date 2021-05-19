#include "Presentation.h"
void Presentation::main()
{
    sf::RenderWindow display(sf::VideoMode(800, 600), "", sf::Style::Close | sf::Style::Titlebar);
    vector<Entity*> entities;

    Windows* window = new Zero;
    window->Screen(display, entities);
    delete window;

    if (entities.empty())
    {
        window = new First;
        window->Screen(display, entities);
        delete window;
    }

    while (display.isOpen())
    {
        window = new Second;
        window->Screen(display, entities);
        delete window;

        if (display.isOpen())
        {
            window = new Third;
            window->Screen(display, entities);
            delete window;
        }
    }
}
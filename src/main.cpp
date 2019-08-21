#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Game");

    Player player(10.0);

    // Window loop
    while (window.isOpen()) 
    {
        sf::Event event;
        // Game loop
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }
        window.clear();
        window.draw();
        window.display();
    }
    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Game");
    Snake snake = Snake(Vector2f(20.0, 20.0), Vector2f(200.0, 200.0));

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

        // Print snake
        for(size_t i = 0; i < snake.getBody().size(); i++)
        {
            RectangleShape bp = snake.getPiece();
            bp.setPosition(snake.getBody()[i]);
            window.draw(bp);
        }
        window.display();
    }
    return 0;
}

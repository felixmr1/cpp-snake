#include <cstdlib>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "food.h"
#include <unistd.h>


// TODO: Refactor these functions into correct classes
Vector2f generateFoodPos(Vector2f size, VideoMode videoSize)
{
    // -- Add food --
    // generate random number for coordinates
    int random_x  = std::rand()%(videoSize.width - (int)size.x);
    int random_y  = std::rand()%(videoSize.height- (int)size.y);

    // make sure that the coordinate is on the "grid"
    float coord_x = (int)((random_x + size.x/2) / size.x) * size.x;
    float coord_y = (int)((random_y + size.y/2) / size.y) * size.y;

    return Vector2f(coord_x, coord_y);
}

void printCoord(Vector2f v)
{
    cout << to_string(v.x) + ":" + to_string(v.y) << endl;
}

int main()
{
    srand(time(NULL));


    VideoMode videoSize(400,400);
    sf::RenderWindow window(videoSize, "Game");
    Snake snake = Snake(Vector2f(20.0, 20.0), Vector2f(200.0, 200.0));
    snake.addBodyPiece();

    Food food = Food(Vector2f(snake.getSize().x, snake.getSize().y));

    window.setFramerateLimit(10);

    Vector2f foodPos = generateFoodPos(snake.getSize(), videoSize);
    food.setPosition(foodPos);

    // Window loop
    while (window.isOpen())
    {
        sf::Event event;
        // Game loop
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // Window closed
                case Event::Closed:
                    window.close();
                    break;

                // Key pressed
                case Event::KeyPressed:
                    if      (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { snake.move('w'); }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { snake.move('s'); }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { snake.move('a'); }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { snake.move('d'); }
                    break;

                // Default
                default:
                    break;
            }
        }
        // Constant move the snake
        snake.move(snake.getDirection());

        window.clear(Color::White);

        // if wall is hit
        // X
        if (snake.getHeadPosition().x > videoSize.width)
        {
            snake.setHeadPosition(Vector2f(0, snake.getHeadPosition().y));
        }
        else if (snake.getHeadPosition().x < 0)
        {
            snake.setHeadPosition(Vector2f(videoSize.width, snake.getHeadPosition().y));
        }
        // Y
        if (snake.getHeadPosition().y > videoSize.height)
        {
            snake.setHeadPosition(Vector2f(snake.getHeadPosition().x, 0));
        }
        else if (snake.getHeadPosition().y < 0)
        {
            snake.setHeadPosition(Vector2f(snake.getHeadPosition().x, videoSize.height));
        }

        // Print snake
        for(auto const& b : snake.getBody())
        {
            RectangleShape bp = snake.getPiece();
            bp.setPosition(b);
            window.draw(bp);
        }


        // position the food
        RectangleShape foodTemplate = food.getPiece();
        foodTemplate.setPosition(food.getPosition());
        window.draw(foodTemplate);

        // if food is eaten
        if (snake.getHeadPosition().x == food.getPosition().x && snake.getHeadPosition().y == food.getPosition().y)
        {
            Vector2f foodPos = generateFoodPos(snake.getSize(), videoSize);

            snake.addBodyPiece();

            // position the food
            food.setPosition(foodPos);
        }

        // Display everything
        window.display();
    }
    return 0;
}


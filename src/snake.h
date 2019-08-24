#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Snake
{
    private:
        Vector2f size;
        RectangleShape piece;

        vector<Vector2f> body;
        char direction;

    public:
        // Init
        //Snake();
        Snake(Vector2f size, Vector2f position);

        // Setters
        void move(char dir);
        void addBodyPiece();
        void setDirection(char direction);
        void setHeadPosition(Vector2f pos);

        // Getters
        vector<Vector2f> getBody();
        RectangleShape getPiece();
        Vector2f getSize();
        char getDirection();
        Vector2f getHeadPosition();
};
#endif

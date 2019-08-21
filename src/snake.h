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

        Vector2f headPosition;
        vector<Vector2f> body;

    public:
        // Init
        //Snake();
        Snake(Vector2f size, Vector2f position);

        // Setters
        void move(char dir);

        // Getters
        vector<Vector2f> getBody();
        RectangleShape getPiece();
};
#endif

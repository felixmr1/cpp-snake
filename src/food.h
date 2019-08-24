#ifndef FOOD_H
#define FOOD_H

#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class Food
{
    private:
        Vector2f position;
        RectangleShape piece;

    public:
        // Init
        Food(Vector2f size);

        // Getters
        Vector2f getPosition();
        RectangleShape getPiece();

        // Setters
        void setPosition(Vector2f position);
};

#endif

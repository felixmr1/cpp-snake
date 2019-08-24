#include "SFML/Graphics.hpp"
#include "food.h"

using namespace sf;
using namespace std;

Food::Food(Vector2f size)
{
    // Create piece
    RectangleShape shape(size);
    shape.setFillColor(Color::Blue);
    this->piece = shape;
}
// Getters
Vector2f Food::getPosition()
{
    return this->position;
}

RectangleShape Food::getPiece()
{
    return this->piece;
}

// Setters
void Food::setPosition(Vector2f position)
{
    this->position = position;
}

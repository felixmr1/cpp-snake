#include "snake.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

Snake::Snake(Vector2f size, Vector2f position)
{
    this->size = size;
    // Add head to top of list
    this->body.push_back(position);

    // Create piece
    RectangleShape bp(this->size);
    bp.setFillColor(Color::Black);
    this->piece = bp;

    // Set direction
    this->direction = 's';

}
// Setters
void Snake::move(char dir)
{
    Vector2f prevHead = this->body[0];

    // First move head
    Vector2f newPos;
    switch (dir)
    {
        case 'w':
            newPos.x = this->body[0].x;
            newPos.y = this->body[0].y - this->size.y;
            this->direction = dir;
            break;
        case 's':
            newPos.x = this->body[0].x;
            newPos.y = this->body[0].y + this->size.y;
            this->direction = dir;
            break;
        case 'a':
            newPos.x = this->body[0].x - this->size.x;
            newPos.y = this->body[0].y;
            this->direction = dir;
            break;
        case 'd':
            newPos.x = this->body[0].x + this->size.x;
            newPos.y = this->body[0].y;
            this->direction = dir;
            break;
    }
    this->body[0] = newPos;

    // then move body
    Vector2f tmp;
    Vector2f tmp2;
    Vector2f tmp3;
    for(size_t i = 1; i < this->body.size(); i++)
    {
        if (i == 1)
        {
             tmp = this->body[i];
             this->body[i] = prevHead;
        }
        else
        {
            tmp2 = this->body[i];
            this->body[i] = tmp;
            tmp3 = tmp;
            tmp = tmp2;
            tmp2 = tmp3;
        }
    }
}

void Snake::addBodyPiece()
{
    this->body.insert(this->body.begin()+1, this->body[0]);
}

void Snake::setDirection(char direction)
{
    this->direction = direction;
}

void Snake::setHeadPosition(Vector2f pos)
{
    this->body[0] = pos;
}

// Getters
vector<Vector2f> Snake::getBody()
{
    return this->body;
}

RectangleShape Snake::getPiece()
{
    return this->piece;
}

Vector2f Snake::getSize()
{
    return this->size;
}

char Snake::getDirection()
{
    return this->direction;
}

Vector2f Snake::getHeadPosition()
{
    return this->body[0];
}

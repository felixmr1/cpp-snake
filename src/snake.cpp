#include "snake.h"

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

Snake::Snake(Vector2f size, Vector2f position)
{
    this->size = size;
    this->headPosition = position;

    // Create piece
    RectangleShape bodyPiece(this->size);
    bodyPiece.setFillColor(Color::White);
    this->piece = bodyPiece;

    // Add headPosition to top of list
    this->body.push_back(this->headPosition);
}
// Setters
void Snake::move(char dir)
{
   // first move body
   Vector2f temp = this->headPosition;
   Vector2f temp2;
   for(size_t i = 1; i < this->body.size(); i++)
   {
       temp2 = this->body[i];
       this->body[i] = temp;
   }

   // then move head
   Vector2f newPos;
   switch (dir)
   {
       case 'w':
           newPos.x = this->size.x;
           newPos.y = this->headPosition.y - this->size.y;
           break;
       case 's':
           newPos.x = this->size.x;
           newPos.y = this->headPosition.y + this->size.y;
           break;
       case 'a':
           newPos.x = this->headPosition.x - this->size.x;
           newPos.y = this->size.y;
           break;
       case 'd':
           newPos.x = this->headPosition.x + this->size.x;
           newPos.y = this->size.y;
           break;
   }
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

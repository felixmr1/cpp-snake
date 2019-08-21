#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

typedef struct BodyPiece
{
    sf::CircleShape piece;
    float position[2];
} BodyPiece;

#endif

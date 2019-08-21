#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "piece.h"
#include <vector>

class Player
{
private:
    float radius;

    sf::CircleShape templateShape;
    std::vector<BodyPiece> body;

public:
    // Init
    Player(float radius);

    void addBodyPiece();

    // Getters
    std::vector<BodyPiece> getBody() { return body; }

    // Setters
    void changePos(float pos);

};

#endif

#include <SFML/Graphics.hpp>
#include "player.h"
#include "piece.h"

Player::Player(float radius)
{
    this->radius = radius;
    this->body.push_back(BodyPiece());
    this->body[0].position[0] = 200.0;
    this->body[0].position[1] = 200.0;
    this->body[0].piece = sf::CircleShape(this->radius);
    this->body[0].piece.setFillColor(sf::Color::Green);
}

void Player::changePos(float pos)
{
    float temp[2] = {this->body[0].position[0], this->body[0].position[1]};
    // First move head
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->body[0].position[0] = 0.0;
        this->body[0].position[1] = -pos;
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->body[0].position[0] = 0.0;
        this->body[0].position[1] = pos;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->body[0].position[0] = -pos;
        this->body[0].position[1] = 0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->body[0].position[0] = pos;
        this->body[0].position[1] = 0.0;
    }

    this->body[0].piece.move(this->body[0].position[0], this->body[0].position[1]);

    for(BodyPiece bp: this->body) {
        bp.piece.move(temp[0], temp[1]);
        temp[0] = bp.position[0];
        temp[1] = bp.position[1];
    }


}

void Player::addBodyPiece() {
    BodyPiece bp;
    bp.piece = sf::CircleShape(this->radius);
    bp.piece.setFillColor(sf::Color::Green);
    this->body.push_back(bp);
}


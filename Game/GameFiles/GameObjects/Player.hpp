#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Wall.hpp"
#include "Box.hpp"
#include "StaticDanger.hpp"
#include "Coin.hpp"

class Player {

private:
    sf::RectangleShape playerShape;

    int shotCooldown;
    int shotCooldownMax;
    int iteration;
    float shotSpeed;
    float moveSpeed;

    float respawnPosX;
    float respawnPosY;

public:
    Player();

    Player(float positionX, float positionY);

    const sf::Vector2f *getCenterPosition() const;

    float getShotSpeed() const;

    sf::FloatRect getBounds() const;

    bool isShotPossible();

    void incrementCooldown();

    void movePlayer(float directionX, float directionY);

    void resetPosition();

    float getPosX() const;

    float getPosY() const;

    float getCenterPosX() const;

    float getCenterPosY() const;

    void setPosition(float positionX, float positionY);

    int getIteration() const;

    void setIteration(int iteration);

    void render(sf::RenderTarget &target);
};
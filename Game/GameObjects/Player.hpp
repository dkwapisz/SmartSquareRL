#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Wall.hpp"
#include "Box.hpp"

class Player {

private:
    sf::RectangleShape playerShape;

    int shotCooldown;
    int shotCooldownMax;
    float shotSpeed;
    float moveSpeed;

    bool checkWallCollision(std::vector<Wall*> &walls, std::vector<Box*> &boxes) const;

public:
    Player();
    Player(float positionX, float positionY);
    virtual ~Player();

    const sf::Vector2f* getCenterPosition() const;

    float getShotSpeed() const;
    sf::FloatRect getBounds() const;
    bool isShotPossible();
    void incrementCooldown();
    void movePlayer(float directionX, float directionY,
                    std::vector<Wall*> &walls,
                    std::vector<Box*> &boxes);
    void render(sf::RenderTarget& target);
};


#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Wall.hpp"

class Player {

private:
    sf::RectangleShape playerShape;

    int shotCooldown;
    int shotCooldownMax;
    float shotSpeed;
    float moveSpeed;

    bool checkWallCollision(std::vector<Wall*> &walls) const;

public:
    Player();
    Player(float positionX, float positionY);
    virtual ~Player();

    const sf::Vector2f* getCenterPosition() const;

    float getShotSpeed() const;
    sf::FloatRect getBounds() const;
    bool isShotPossible();
    void incrementCooldown();
    void movePlayer(float directionX, float directionY, std::vector<Wall*> &walls);
    void render(sf::RenderTarget& target);
};


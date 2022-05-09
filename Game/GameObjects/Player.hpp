#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player {

private:
    sf::RectangleShape playerSquare;

    int shotCooldown;
    int shotCooldownMax;
    float moveSpeed;
    void initializeSquare();

public:
    Player();
    virtual ~Player();

    const sf::Vector2f* getCenterPosition() const;

    void incrementCooldown();
    bool isShotPossible();
    void move(float directionX, float directionY);
    void render(sf::RenderTarget& target);
};


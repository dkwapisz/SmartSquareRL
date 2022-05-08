#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player {

private:
    sf::RectangleShape playerSquare;

    float moveSpeed;
    void initializeSquare();

public:
    Player();
    virtual ~Player();

    void move(float directionX, float directionY);
    void update();
    void render(sf::RenderTarget& target);
};


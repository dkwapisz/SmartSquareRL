#ifndef BULLET_HPP
#define BULLET_HPP

#include "SquareObject.hpp"

class Bullet : public SquareObject {

private:
    sf::Vector2f direction;
    float moveSpeed{};

public:
    Bullet();
    Bullet(sf::RectangleShape* bulletShape,
           float positionX, float positionY,
           float directionX, float directionY,
           float moveSpeed);
    virtual ~Bullet();

    void update();
};

#endif //BULLET_HPP
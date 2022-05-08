#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet {

private:
    sf::RectangleShape bulletShape;
    sf::Vector2f direction;
    float moveSpeed{};

public:
    Bullet();
    Bullet(sf::RectangleShape bulletShape, float directionX, float directionY, float moveSpeed);
    virtual ~Bullet();

    void update();
    void render(sf::RenderTarget* target);
};

#endif //BULLET_HPP
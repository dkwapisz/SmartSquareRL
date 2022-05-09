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
    Bullet(sf::RectangleShape* bulletShape,
           float positionX, float positionY,
           float directionX, float directionY,
           float moveSpeed);
    virtual ~Bullet();

    sf::FloatRect getBounds() const;

    void update();
    void render(sf::RenderTarget* target);
};

#endif //BULLET_HPP
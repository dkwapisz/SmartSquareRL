#include "Bullet.hpp"

Bullet::Bullet() = default;

Bullet::Bullet(sf::RectangleShape* bulletShape,
               float positionX, float positionY,
               float directionX, float directionY,
               float moveSpeed) {
    this -> bulletShape = *bulletShape;
    this -> direction.x = directionX;
    this -> direction.y = directionY;
    this -> moveSpeed = moveSpeed;

    this -> bulletShape.setPosition(positionX, positionY);
    this -> bulletShape.setFillColor(sf::Color::Red);
    this -> bulletShape.setSize(sf::Vector2f(5.f, 5.f));
}

Bullet::~Bullet() = default;

void Bullet::update() {
    this -> bulletShape.move(this -> moveSpeed * this -> direction);

}

void Bullet::render(sf::RenderTarget *target) {
    target -> draw(this -> bulletShape);
}

sf::FloatRect Bullet::getBounds() const {
    return this -> bulletShape.getGlobalBounds();
}



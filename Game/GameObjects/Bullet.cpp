#include "Bullet.hpp"

Bullet::Bullet() = default;

Bullet::Bullet(sf::RectangleShape bulletShape, float directionX, float directionY, float moveSpeed) {
    this -> bulletShape = bulletShape;
    this -> direction.x = directionX;
    this -> direction.y = directionY;
    this -> moveSpeed = moveSpeed;

    bulletShape.setFillColor(sf::Color::Red);
}

Bullet::~Bullet() {

}

void Bullet::update() {
    this -> bulletShape.move(this -> moveSpeed * this -> direction);

}

void Bullet::render(sf::RenderTarget *target) {
    target -> draw(this -> bulletShape);
}



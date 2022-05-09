#include "Player.hpp"

Player::Player() {

    this -> moveSpeed = 2.f;
    this -> shotCooldown = 10;
    this -> shotCooldownMax = 10;

    initializeSquare();
}

Player::~Player() = default;

void Player::initializeSquare() {
    this -> playerSquare.setFillColor(sf::Color::Blue);
    this -> playerSquare.setSize(sf::Vector2f(30.f, 30.f));
}

void Player::render(sf::RenderTarget &target) {
    target.draw(this -> playerSquare);
}

void Player::move(float directionX, float directionY) {
    this -> playerSquare.move(this -> moveSpeed * directionX, this -> moveSpeed * directionY);
}

const sf::Vector2f* Player::getCenterPosition() const {
    float x = this -> playerSquare.getPosition().x + playerSquare.getSize().x / 2;
    float y = this -> playerSquare.getPosition().y + playerSquare.getSize().y / 2;

    auto *centerPosition = new sf::Vector2f(x, y);

    return centerPosition;
}

void Player::incrementCooldown() {
    shotCooldown++;
}

bool Player::isShotPossible() {
    if (shotCooldown >= shotCooldownMax) {
        shotCooldown = 0;
        return true;
    } else {
        return false;
    }
}

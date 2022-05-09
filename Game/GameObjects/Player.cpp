#include "Player.hpp"
#include <iostream>

Player::Player() {
    this -> moveSpeed = 2.f;
    this -> shotCooldown = 10;
    this -> shotCooldownMax = 10;
    this -> shotSpeed = 4.f;

    this -> playerShape.setFillColor(sf::Color::Blue);
    this -> playerShape.setSize(sf::Vector2f(20.f, 20.f));
}

Player::~Player() = default;

void Player::render(sf::RenderTarget &target) {
    target.draw(this -> playerShape);
}

bool Player::checkWallCollision(std::vector<Wall*> &walls) const {
    for (const auto& wall : walls) {
        if (wall -> getBounds().intersects(this -> getBounds())) {
            return true;
        }
    }
    return false;
}

void Player::movePlayer(float directionX, float directionY, std::vector<Wall*> &walls) {
    float startPosX = playerShape.getPosition().x;
    float startPosY = playerShape.getPosition().y;

    this -> playerShape.move(this -> moveSpeed * directionX, this -> moveSpeed * directionY);

    if (checkWallCollision(walls)) {
        playerShape.setPosition(startPosX, startPosY);
    }
}

const sf::Vector2f* Player::getCenterPosition() const {
    float x = this -> playerShape.getPosition().x + playerShape.getSize().x / 2;
    float y = this -> playerShape.getPosition().y + playerShape.getSize().y / 2;

    auto *centerPosition = new sf::Vector2f(x, y);

    return centerPosition;
}

void Player::incrementCooldown() {
    shotCooldown++;
}

float Player::getShotSpeed() const {
    return shotSpeed;
}

sf::FloatRect Player::getBounds() const {
    return this -> playerShape.getGlobalBounds();
}

bool Player::isShotPossible() {
    if (shotCooldown >= shotCooldownMax) {
        shotCooldown = 0;
        return true;
    } else {
        return false;
    }
}

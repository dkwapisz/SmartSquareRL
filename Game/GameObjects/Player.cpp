#include "Player.hpp"

Player::Player() = default;

//TODO -> Inheritance GameObject class <-> all gameObjects

Player::Player(float positionX, float positionY) {
    this -> moveSpeed = 2.f;
    this -> shotCooldown = 10;
    this -> shotCooldownMax = 10;
    this -> shotSpeed = 4.f;

    this -> respawnPosX = positionX;
    this -> respawnPosY = positionY;

    this -> playerShape.setPosition(positionX, positionY);
    this -> playerShape.setFillColor(sf::Color::Blue);
    this -> playerShape.setSize(sf::Vector2f(20.f, 20.f));
}

Player::~Player() = default;

void Player::render(sf::RenderTarget &target) {
    target.draw(this -> playerShape);
}

bool Player::checkWallCollision(std::vector<Wall*> &walls,
                                std::vector<Box*> &boxes,
                                std::vector<StaticDanger*> &staticDangers) {

    for (const auto& wall : walls) {
        if (wall -> getBounds().intersects(this -> getBounds())) {
            return true;
        }
    }

    for (const auto& box : boxes) {
        if (box -> getBounds().intersects(this -> getBounds())) {
            return true;
        }
    }

    for (const auto& staticDanger : staticDangers) {
        if (staticDanger -> getBounds().intersects(this -> getBounds())) {
            this -> resetPosition();
            return false;
        }
    }

    return false;
}

void Player::resetPosition() {
    this -> playerShape.setPosition(respawnPosX, respawnPosY);
}

void Player::movePlayer(float directionX, float directionY,
                        std::vector<Wall*> &walls,
                        std::vector<Box*> &boxes,
                        std::vector<StaticDanger*> &staticDangers) {

    float startPosX = playerShape.getPosition().x;
    float startPosY = playerShape.getPosition().y;

    this -> playerShape.move(this -> moveSpeed * directionX, this -> moveSpeed * directionY);

    if (checkWallCollision(walls, boxes, staticDangers)) {
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

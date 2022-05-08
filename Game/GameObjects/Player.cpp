#include "Player.hpp"

Player::Player() {

    this -> moveSpeed = 2.f;

    initializeSquare();
}

Player::~Player() {

}

void Player::initializeSquare() {
    this -> playerSquare.setFillColor(sf::Color::Blue);
    this -> playerSquare.setSize(sf::Vector2f(30.f, 30.f));
}

void Player::update() {

}

void Player::render(sf::RenderTarget &target) {
    target.draw(this -> playerSquare);
}

void Player::move(float directionX, float directionY) {
    this -> playerSquare.move(this -> moveSpeed * directionX, this -> moveSpeed * directionY);
}


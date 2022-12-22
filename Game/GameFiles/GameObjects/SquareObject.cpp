// Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
// License:      GPLv3

#include "SquareObject.hpp"

SquareObject::SquareObject() = default;

SquareObject::SquareObject(sf::RectangleShape *objectShape, float posX, float posY) {
    this->objectShape = *objectShape;
    this->objectShape.setPosition(posX, posY);
}

sf::FloatRect SquareObject::getBounds() const {
    return this->objectShape.getGlobalBounds();
}

void SquareObject::render(sf::RenderTarget &target) {
    target.draw(this->objectShape);
}

float SquareObject::getCenterPosX() const {
    return this->objectShape.getPosition().x + objectShape.getSize().x / 2;
}

float SquareObject::getCenterPosY() const {
    return this->objectShape.getPosition().y + objectShape.getSize().y / 2;
}

sf::RectangleShape &SquareObject::getObjectShape() {
    return objectShape;
}

#include "CircleObject.hpp"

CircleObject::CircleObject() = default;

CircleObject::CircleObject(sf::CircleShape *objectShape, float positionX, float positionY) {
    this -> objectShape = *objectShape;
    this -> objectShape.setRadius(10.f);
    this -> objectShape.setPosition(positionX + this -> objectShape.getRadius() / 2,
                                    positionY + this -> objectShape.getRadius() / 2);
}

sf::FloatRect CircleObject::getBounds() const {
    return this -> objectShape.getGlobalBounds();
}

void CircleObject::render(sf::RenderTarget &target) {
    target.draw(this -> objectShape);
}

//TODO Check if it's center position!
float CircleObject::getCenterPosX() const {
    return this -> objectShape.getPosition().x;
}

float CircleObject::getCenterPosY() const {
    return this -> objectShape.getPosition().y;
}
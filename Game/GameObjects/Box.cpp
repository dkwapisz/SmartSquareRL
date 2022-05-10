#include "Box.hpp"

Box::Box() = default;

Box::Box(sf::RectangleShape *boxShape, float positionX, float positionY) {
    this -> boxShape = *boxShape;

    this -> boxShape.setPosition(positionX, positionY);
    this -> boxShape.setFillColor(sf::Color(50, 0, 0));
    this -> boxShape.setSize(sf::Vector2f(30.f, 30.f));
}

Box::~Box() = default;

sf::FloatRect Box::getBounds() const {
    return this -> boxShape.getGlobalBounds();
}

void Box::render(sf::RenderTarget *target) {
    target -> draw(this -> boxShape);
}

#include "Floor.hpp"

Floor::Floor() = default;

Floor::Floor(sf::RectangleShape *floorShape, float positionX, float positionY) :
        SquareObject(floorShape, positionX, positionY) {
    this->discovered = false;
    this->objectShape.setSize(sf::Vector2f(30.f, 30.f));
}

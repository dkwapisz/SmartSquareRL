#include "Wall.hpp"

Wall::Wall() = default;

Wall::Wall(sf::RectangleShape *wallShape, float positionX, float positionY) {
    this -> wallShape = *wallShape;

    this -> wallShape.setPosition(positionX, positionY);
    this -> wallShape.setFillColor(sf::Color(100, 100, 100));
    this -> wallShape.setSize(sf::Vector2f(30.f, 30.f));
}

Wall::~Wall() = default;

sf::FloatRect Wall::getBounds() const {
    return this -> wallShape.getGlobalBounds();
}

void Wall::render(sf::RenderTarget *target) {
    target -> draw(this -> wallShape);
}

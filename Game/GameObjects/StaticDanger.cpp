#include "StaticDanger.hpp"

StaticDanger::StaticDanger() = default;

StaticDanger::StaticDanger(sf::RectangleShape *staticDangerShape, float positionX, float positionY) {
    this -> staticDangerShape = *staticDangerShape;

    this -> staticDangerShape.setPosition(positionX, positionY);
    this -> staticDangerShape.setFillColor(sf::Color(170, 0, 140));
    this -> staticDangerShape.setSize(sf::Vector2f(30.f, 30.f));
}

StaticDanger::~StaticDanger() = default;

sf::FloatRect StaticDanger::getBounds() const {
    return staticDangerShape.getGlobalBounds();
}

void StaticDanger::render(sf::RenderTarget *target) {
    target -> draw(this -> staticDangerShape);
}

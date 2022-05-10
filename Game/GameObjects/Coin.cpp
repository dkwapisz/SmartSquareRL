#include "Coin.hpp"


Coin::Coin() = default;

Coin::Coin(sf::CircleShape *coinShape, float positionX, float positionY) {
    this -> coinShape = *coinShape;

    this -> coinShape.setRadius(10.f);
    this -> coinShape.setPosition(positionX + this -> coinShape.getRadius() / 2,
                                  positionY + this -> coinShape.getRadius() / 2);
    this -> coinShape.setFillColor(sf::Color(255, 255, 0));

}

Coin::~Coin() = default;

sf::FloatRect Coin::getBounds() const {
    return coinShape.getGlobalBounds();
}

void Coin::render(sf::RenderTarget *target) {
    target -> draw(this -> coinShape);
}



#include "Coin.hpp"


Coin::Coin() = default;

Coin::Coin(sf::CircleShape *coinShape, float positionX, float positionY) :
        CircleObject(coinShape, positionX, positionY) {

    this->objectShape.setFillColor(sf::Color(255, 255, 0));

}

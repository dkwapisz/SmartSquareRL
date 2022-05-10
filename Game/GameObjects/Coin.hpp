#ifndef COIN_HPP
#define COIN_HPP

#include <SFML/Graphics.hpp>
#include "CircleObject.hpp"

class Coin : public CircleObject {

public:
    Coin();
    Coin(sf::CircleShape* coinShape, float positionX, float positionY);
    virtual ~Coin();
};

#endif //COIN_HPP

#ifndef COIN_HPP
#define COIN_HPP

#include "CircleObject.hpp"

class Coin : public CircleObject {

public:
    Coin();
    Coin(sf::CircleShape* coinShape, float positionX, float positionY);
    ~Coin();
};

#endif //COIN_HPP

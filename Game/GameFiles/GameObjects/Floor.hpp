#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "SquareObject.hpp"

class Floor : public SquareObject {

public:
    Floor();

    Floor(sf::RectangleShape *wallShape, float positionX, float positionY);

    bool discovered;
};


#endif //FLOOR_HPP

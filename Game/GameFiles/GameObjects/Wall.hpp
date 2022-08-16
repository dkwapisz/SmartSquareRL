#ifndef WALL_HPP
#define WALL_HPP

#include "SquareObject.hpp"

class Wall : public SquareObject {

public:
    Wall();

    Wall(sf::RectangleShape *wallShape, float positionX, float positionY);

    bool discovered;
};


#endif //WALL_HPP

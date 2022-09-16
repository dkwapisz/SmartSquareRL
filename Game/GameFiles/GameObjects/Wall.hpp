#ifndef WALL_HPP
#define WALL_HPP

#include "SquareObject.hpp"

class Wall : public SquareObject {

public:
    Wall();

    Wall(sf::RectangleShape *wallShape, float positionX, float positionY);

};


#endif //WALL_HPP

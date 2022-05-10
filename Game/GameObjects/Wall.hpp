#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include "SquareObject.hpp"

class Wall : public SquareObject {

public:
    Wall();
    Wall(sf::RectangleShape* wallShape, float positionX, float positionY);
    virtual ~Wall();
};


#endif //WALL_HPP

#ifndef BOX_HPP
#define BOX_HPP

#include "SquareObject.hpp"

class Box : public SquareObject {

public:
    Box();
    Box(sf::RectangleShape* boxShape, float positionX, float positionY);
    ~Box() override;
};


#endif //BOX_HPP

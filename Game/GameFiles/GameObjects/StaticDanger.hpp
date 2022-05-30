#ifndef STATICDANGER_HPP
#define STATICDANGER_HPP

#include "SquareObject.hpp"

class StaticDanger : public SquareObject {

public:
    StaticDanger();
    StaticDanger(sf::RectangleShape* staticDangerShape, float positionX, float positionY);
};


#endif //STATICDANGER_HPP

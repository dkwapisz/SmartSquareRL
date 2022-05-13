#ifndef FINISH_HPP
#define FINISH_HPP

#include "SquareObject.hpp"

class Finish : public SquareObject {

public:
    Finish();
    Finish(sf::RectangleShape* wallShape, float positionX, float positionY);
    ~Finish();
};


#endif //FINISH_HPP
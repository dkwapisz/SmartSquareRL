#ifndef SQUAREOBJECT_HPP
#define SQUAREOBJECT_HPP

#include <SFML/Graphics.hpp>

class SquareObject {

protected:
    sf::RectangleShape objectShape;

public:
    SquareObject();
    SquareObject(sf::RectangleShape* objectShape, float posX, float posY);
    ~SquareObject();

    sf::FloatRect getBounds() const;

    void render(sf::RenderTarget &target);
};


#endif //SQUAREOBJECT_HPP

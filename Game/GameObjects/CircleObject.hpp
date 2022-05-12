#ifndef CIRCLEOBJECT_HPP
#define CIRCLEOBJECT_HPP

#include <SFML/Graphics.hpp>

class CircleObject {

protected:
    sf::CircleShape objectShape;

public:
    CircleObject();
    CircleObject(sf::CircleShape* objectShape, float posX, float posY);
    virtual ~CircleObject();

    sf::FloatRect getBounds() const;

    void render(sf::RenderTarget &target);
};


#endif //CIRCLEOBJECT_HPP

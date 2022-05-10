#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>

class Box {

private:
    sf::RectangleShape boxShape;

public:
    Box();
    Box(sf::RectangleShape* boxShape, float positionX, float positionY);
    virtual ~Box();

    sf::FloatRect getBounds() const;

    void render(sf::RenderTarget* target);
};


#endif //BOX_HPP

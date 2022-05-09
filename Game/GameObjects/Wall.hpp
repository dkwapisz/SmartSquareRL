#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>

class Wall {

private:
    sf::RectangleShape wallShape;

public:
    Wall();
    Wall(sf::RectangleShape* wallShape, float positionX, float positionY);
    virtual ~Wall();

    sf::FloatRect getBounds() const;

    void render(sf::RenderTarget* target);
};


#endif //WALL_HPP

#ifndef COIN_HPP
#define COIN_HPP

#include <SFML/Graphics.hpp>


class Coin {

private:
    sf::CircleShape coinShape;

public:
    Coin();
    Coin(sf::CircleShape* boxShape, float positionX, float positionY);
    virtual ~Coin();

    sf::FloatRect getBounds() const;

    void render(sf::RenderTarget* target);

};

#endif //COIN_HPP

#ifndef STATICDANGER_HPP
#define STATICDANGER_HPP

#include <SFML/Graphics.hpp>

class StaticDanger {

private:
    sf::RectangleShape staticDangerShape;

public:
    StaticDanger();
    StaticDanger(sf::RectangleShape* staticDangerShape, float positionX, float positionY);
    virtual ~StaticDanger();

    sf::FloatRect getBounds() const;

    void render(sf::RenderTarget* target);

};


#endif //STATICDANGER_HPP

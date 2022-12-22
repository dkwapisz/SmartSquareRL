// Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
// License:      GPLv3

#include "Floor.hpp"

Floor::Floor() = default;

Floor::Floor(sf::RectangleShape *floorShape, float positionX, float positionY) :
        SquareObject(floorShape, positionX, positionY) {
    this->discovered = false;
    this->objectShape.setFillColor(sf::Color(0, 0, 0));
    this->objectShape.setSize(sf::Vector2f(30.f, 30.f));
}

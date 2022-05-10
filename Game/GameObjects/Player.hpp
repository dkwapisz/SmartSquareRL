#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Wall.hpp"
#include "Box.hpp"
#include "StaticDanger.hpp"
#include "Coin.hpp"

class Player {

private:
    sf::RectangleShape playerShape;

    int shotCooldown;
    int shotCooldownMax;
    int playerCoins;
    float shotSpeed;
    float moveSpeed;

    float respawnPosX;
    float respawnPosY;

    bool checkCollision(std::vector<Wall*> &walls,
                        std::vector<Box*> &boxes,
                        std::vector<StaticDanger*> &staticDangers,
                        std::vector<Coin*> &coins);

public:
    Player();
    Player(float positionX, float positionY);
    virtual ~Player();

    const sf::Vector2f* getCenterPosition() const;

    float getShotSpeed() const;
    int getPlayerCoins() const;
    sf::FloatRect getBounds() const;
    bool isShotPossible();
    void incrementCooldown();
    void movePlayer(float directionX, float directionY,
                    std::vector<Wall*> &walls,
                    std::vector<Box*> &boxes,
                    std::vector<StaticDanger*> &staticDangers,
                    std::vector<Coin*> &coins);
    void resetPosition();
    void render(sf::RenderTarget& target);
};


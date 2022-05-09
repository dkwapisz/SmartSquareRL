#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GameObjects/Player.hpp"
#include "GameObjects/Bullet.hpp"
#include <map>

class Game {

private:
    sf::RenderWindow* window;

    std::map<std::string, sf::RectangleShape*> gameObjectsShape;
    std::vector<Bullet*> bullets;
    Player* player;

    void initializeWindow();
    void initializeGameObjects();
    void initializePlayer();
    void inputMovement();
    void inputShooting();
    void shot(float directionX, float directionY);

public:
    Game();
    virtual ~Game();

    void run();
    void updateWindowEvents();
    void updatePlayerInput();
    void updateBullets();
    void update();
    void render();

};

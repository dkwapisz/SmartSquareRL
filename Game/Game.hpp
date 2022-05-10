#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GameObjects/Player.hpp"
#include "GameObjects/Bullet.hpp"
#include "GameObjects/Wall.hpp"
#include "GameObjects/Box.hpp"
#include "GameObjects/StaticDanger.hpp"
#include "GameObjects/Coin.hpp"
#include <iostream>
#include <fstream>
#include <map>

class Game {

private:
    sf::RenderWindow* window;

    std::map<std::string, sf::RectangleShape*> rectangleShapes;
    std::map<std::string, sf::CircleShape*> circleShapes;
    std::vector<Bullet*> bullets;
    std::vector<Wall*> walls;
    std::vector<Box*> boxes;
    std::vector<StaticDanger*> staticDangers;
    std::vector<Coin*> coins;
    Player* player;

    int coinsCount;

    void initializeWindow();
    void initializeGameObjects();
    void generateMap();
    void inputMovement();
    void movePlayer(float directionX, float directionY);
    bool checkCollision();
    void inputShooting();
    void checkPlayerCoins();
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

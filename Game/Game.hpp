#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GameObjects/Player.hpp"
#include "GameObjects/Bullet.hpp"
#include "GameObjects/Wall.hpp"
#include "GameObjects/Box.hpp"
#include "GameObjects/StaticDanger.hpp"
#include "GameObjects/Coin.hpp"
#include "GameObjects/MovingDanger.hpp"
#include "GameObjects/Finish.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

class Game {

private:
    sf::RenderWindow* window;
    sf::Clock* clock;
    sf::Text* clockLabel;
    sf::Text* coinCountLabel;
    sf::Text* deathCountLabel;
    sf::Font* font;

    std::map<std::string, sf::RectangleShape*> squareShapes;
    std::map<std::string, sf::CircleShape*> circleShapes;
    std::vector<Bullet*> bullets;
    std::vector<Wall*> walls;
    std::vector<Box*> boxes;
    std::vector<StaticDanger*> staticDangers;
    std::vector<Coin*> coins;
    std::vector<MovingDanger*> movingDangers;
    std::vector<Finish*> finishes;
    std::string mapPath;

    Player* player;

    int coinsCount;

    void loadFont();
    void initializeWindow();
    void initializeGameObjects();
    void generateMap();
    void inputMovement();
    void movePlayer(float directionX, float directionY);
    bool checkCollision();
    void inputShooting();
    bool checkPlayerCoins();
    void shot(float directionX, float directionY);
    void finishLevel();
    void initializeLabels();
    void deleteLabels();
    void updateLabels();
    void renderLabels();
    void resetLevel();

public:
    Game();
    virtual ~Game();

    void run();
    void updateWindowEvents();
    void updatePlayerInput();
    void updateBullets();
    void updateDangerMovement();
    void checkDangerCollision(MovingDanger *movingDanger);
    void update();
    void render();

};

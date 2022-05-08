#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GameObjects/Player.hpp"
#include <map>

class Game {

private:
    sf::RenderWindow* window;

    std::map<std::string, sf::RectangleShape> gameObjects;
    Player* player;

    void initializeWindow();
    void initializeGameObjects();
    void initializePlayer();

public:
    Game();
    virtual ~Game();

    void run();
    void updateWindowEvents();
    void updatePlayerInput();
    void update();
    void render();

};

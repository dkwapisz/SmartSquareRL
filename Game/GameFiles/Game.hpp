#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Level.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include "../ProtoClient/ProtoClient.hpp"

class Game {

private:
    sf::RenderWindow *window;
    sf::Text *clockLabel;
    sf::Text *coinCountLabel;
    sf::Text *iterationCountLabel;
    sf::Font *font;

    Level *level;
    bool gameFinished;

    void loadFont();
    void initializeWindow();
    void initializeLabels();

    void inputMovement(char direction);
    void inputShooting(char direction);

    void deleteLabels();

    void updateLabels();
    void updateWindowEvents();
    void updatePlayerInput(char moveDirection, char shotDirection);
    bool playStep(char moveDirection, char shotDirection);

    void renderLabels();
    void render();
    void performResetIfNeeded(bool reset);

    GameMessage::State_ObjectDirection convertDirFromChar(char dir);

public:
    Game();
    virtual ~Game();
    void run();

};

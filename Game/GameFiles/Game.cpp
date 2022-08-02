#include "Game.hpp"

Game::Game() {
    this -> loadFont();
    this -> initializeWindow();
    this -> initializeLabels();

    this -> gameFinished = false;
    this -> level = new Level(1);
}

Game::~Game() {
    delete this -> level;
    deleteLabels();
    delete this -> window;
    exit(0);
}

void Game::loadFont() {
    this -> font = new sf::Font();

    if (!font -> loadFromFile("../Game/GameFiles/Upheaval-font.ttf")) {
        std::cout << "Font cannot be loaded";
    }
}

void Game::initializeWindow() {
    this -> window = new sf::RenderWindow(sf::VideoMode(600, 650),
                                          "SmartSquareRL",
                                          sf::Style::Close | sf::Style::Titlebar);
    this -> window -> setFramerateLimit(75);
    this -> window -> setVerticalSyncEnabled(false);
}

void Game::initializeLabels() {
    this -> clockLabel = new sf::Text();
    this -> iterationCountLabel = new sf::Text();
    this -> coinCountLabel = new sf::Text();

    clockLabel -> setFont(*font);
    iterationCountLabel -> setFont(*font);
    coinCountLabel -> setFont(*font);

    clockLabel -> setPosition(10.f, 10.f);
    iterationCountLabel -> setPosition(240.f, 10.f);
    coinCountLabel -> setPosition(480.f, 10.f);

    clockLabel -> setFillColor(sf::Color::White);
    iterationCountLabel -> setFillColor(sf::Color::White);
    coinCountLabel -> setFillColor(sf::Color::White);

    clockLabel -> setCharacterSize(22);
    iterationCountLabel -> setCharacterSize(22);
    coinCountLabel -> setCharacterSize(22);
}

void Game::deleteLabels() {
    delete this -> clockLabel;
    delete this -> iterationCountLabel;
    delete this -> coinCountLabel;
    delete this -> font;
}

void Game::updateLabels() {
    std::string time = std::to_string(this -> level -> getClockTime());
    clockLabel -> setString("Time: " + time + " [s]");

    std::string iteration = std::to_string(this -> level -> getPlayer() -> getIteration());
    iterationCountLabel -> setString("Iteration: " + iteration);

    std::string coinsCollected = std::to_string(this -> level -> getPlayerCoinsCount());
    std::string allCoins = std::to_string(this -> level -> getCoinsCount());
    coinCountLabel -> setString(coinsCollected + "/" + allCoins + " coins");
}

void Game::renderLabels() {
    this -> window -> draw(*clockLabel);
    this -> window -> draw(*iterationCountLabel);
    this -> window -> draw(*coinCountLabel);
}

void Game::run() {
    ProtoClient client{grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())};
    bool gameOver;
    char* action;
    bool reset;

    while (this -> window -> isOpen()) {
        if (!gameFinished) {
            // TODO Refactor
            if (level -> getReward() > 0) {
                level -> resetClockTime();
            }

            action = client.StateAction(level -> isClosestObstacleBox(),
                                        level -> areCoinsNeeded(),
                                        convertDirFromChar(level -> getClosestObstacleDir()),
                                        convertDirFromChar(level -> getClosestCoinDir()),
                                        convertDirFromChar(level -> getClosestEnemyDir()),
                                        convertDirFromChar(level -> getFinishDirectionDir()),
                                        level -> getClockTime(),
                                        level -> getPlayer() -> getIteration());

            gameOver = this -> playStep(action[0], action[1]);
            std::cout << "Move action: " << action[0] << "\n";
            this -> render();

            reset = client.StateReset(level -> isClosestObstacleBox(),
                                      level -> areCoinsNeeded(),
                                      convertDirFromChar(level -> getClosestObstacleDir()),
                                      convertDirFromChar(level -> getClosestCoinDir()),
                                      convertDirFromChar(level -> getClosestEnemyDir()),
                                      convertDirFromChar(level -> getFinishDirectionDir()),
                                      level -> getReward(),
                                      level -> isGameOver());

            performResetIfNeeded(gameOver || reset);
        } else {
            this -> window -> close();
            delete this;
            return;
        }
    }
}

void Game::updateWindowEvents() {
    sf::Event e;

    while (this -> window -> pollEvent(e)) {
        if (e.Event::type == sf::Event::Closed) {
            this -> window -> close();
        }
    }
}

void Game::updatePlayerInput(char moveDirection, char shotDirection) {
    inputMovement(moveDirection);
    inputShooting(shotDirection);
}

void Game::inputMovement(char direction) {
    if (direction == 'L') {
        this -> level -> movePlayer(-1.f, 0.f);
    }
    if (direction == 'R') {
        this -> level -> movePlayer(1.f, 0.f);
    }
    if (direction == 'U') {
        this -> level -> movePlayer(0.f, -1.f);
    }
    if (direction == 'D') {
        this -> level -> movePlayer(0.f, 1.f);
    }
}

void Game::inputShooting(char direction) {
    if (direction == 'L') {
        this -> level -> shot(-1.f, 0.f);
    }
    if (direction == 'R') {
        this -> level -> shot(1.f, 0.f);
    }
    if (direction == 'U') {
        this -> level -> shot(0.f, -1.f);
    }
    if (direction == 'D') {
        this -> level -> shot(0.f, 1.f);
    }
}

bool Game::playStep(char moveDirection, char shotDirection) {
    this -> updateWindowEvents();
    this -> updatePlayerInput(moveDirection, shotDirection);
    this -> updateLabels();

    this -> level -> updateBullets();
    this -> level -> updateDangerMovement();
    this -> level -> calculateClosestObjectsDir();

    if (this -> level -> isLevelFinished()) {
        return true;

        // TODO Think what to do with this (probably just reset level)
        int lastLevelNum = this -> level -> getLevelNumber();
        int mapsCount = this -> level -> getMapsCount();

        if (lastLevelNum + 1 > mapsCount) {
            std::cout << "Player wins \n";
            gameFinished = true;
        } else {
            delete this -> level;
            this -> level = new Level(lastLevelNum + 1);
        }
    }

    return this -> level -> isGameOver();
}

void Game::render() {
    this -> window -> clear();

    this -> level -> renderGameObjects(*this -> window);
    renderLabels();

    this -> window -> display();
}

void Game::performResetIfNeeded(bool reset) {
    if (reset) {
        this -> level -> resetLevel();
        this -> level -> setGameOver(false);
    }
}

GameMessage::State_ObjectDirection Game::convertDirFromChar(char dir) {
    if (dir == 'U') {
        return GameMessage::State_ObjectDirection_UP;
    }
    else if (dir == 'R') {
        return GameMessage::State_ObjectDirection_RIGHT;
    }
    else if (dir == 'D') {
        return GameMessage::State_ObjectDirection_DOWN;
    }
    else if (dir == 'L') {
        return GameMessage::State_ObjectDirection_LEFT;
    }
    else {
        return GameMessage::State_ObjectDirection_NOT_EXIST;
    }
}
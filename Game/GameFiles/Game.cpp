// Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
// License:      GPLv3

#include "Game.hpp"

Game::Game() {
    MAP_SIZE = 20;
    this->renderGame = false;

    if (renderGame) {
        this->loadFont();
        this->initializeWindow();
        this->initializeLabels();
    }

    this->gameFinished = false;
    this->level = new Level(0, MAP_SIZE);
}

Game::~Game() {
    delete this->level;
    if (renderGame) {
        deleteLabels();
        delete this->window;
    }
    exit(0);
}

void Game::loadFont() {
    this->font = new sf::Font();

    if (!font->loadFromFile("../Game/GameFiles/Upheaval-font.ttf")) {
        std::cerr << "Font cannot be loaded. Trying second path..." << "\n";
        if (!font->loadFromFile("/home/dkwapisz/SmartSquareRL/cmake-build-release/Upheaval-font.ttf")) {
            std::cerr << "Font cannot be loaded anyway. Aborted..." << "\n";
        }
    }
}

void Game::initializeWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(600, 650),
                                        "SmartSquareRL",
                                        sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(200);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initializeLabels() {
    this->stepsLabel = new sf::Text();
    this->iterationCountLabel = new sf::Text();
    this->coinCountLabel = new sf::Text();

    stepsLabel->setFont(*font);
    iterationCountLabel->setFont(*font);
    coinCountLabel->setFont(*font);

    stepsLabel->setPosition(10.f, 10.f);
    iterationCountLabel->setPosition(240.f, 10.f);
    coinCountLabel->setPosition(480.f, 10.f);

    stepsLabel->setFillColor(sf::Color::White);
    iterationCountLabel->setFillColor(sf::Color::White);
    coinCountLabel->setFillColor(sf::Color::White);

    stepsLabel->setCharacterSize(22);
    iterationCountLabel->setCharacterSize(22);
    coinCountLabel->setCharacterSize(22);
}

void Game::deleteLabels() {
    delete this->stepsLabel;
    delete this->iterationCountLabel;
    delete this->coinCountLabel;
    delete this->font;
}

void Game::updateLabels() {
    std::string step = std::to_string(this->level->gameStateHandling->stepsCount);
    stepsLabel->setString("Step: " + step);

    std::string episodes = std::to_string(this->level->getPlayer()->getEpisodeNumber());
    iterationCountLabel->setString("Episode: " + episodes);

    std::string coinsCollected = std::to_string(this->level->getPlayerCoinsCount());
    std::string allCoins = std::to_string(this->level->getCoinsCount());
    coinCountLabel->setString(coinsCollected + "/" + allCoins + " coins");
}

void Game::renderLabels() {
    this->window->draw(*stepsLabel);
    this->window->draw(*iterationCountLabel);
    this->window->draw(*coinCountLabel);
}

void Game::run(int argc, char **argv) {
    std::string client_address = "localhost:";
    client_address.append(argv[1]);

    std::cout << "Client starts in address: " << client_address << "\n";
    ProtoClient client{grpc::CreateChannel(client_address, grpc::InsecureChannelCredentials())};

    bool gameOver;
    char *actions;
    bool reset;
    int coinsLeft;

    while (!renderGame || (this->window->isOpen())) {
        if (!gameFinished) {
            this->level->gameStateHandling->reward = 0;

            coinsLeft = level->getCoinsCount() - level->getPlayerCoinsCount();

            actions = client.StateAction(level->gameStateHandling, coinsLeft,
                                         level->getPlayer()->getEpisodeNumber());

            gameOver = this->playStep(actions[0], actions[1]);

            if (renderGame) {
                this->render();
            }

            reset = client.StateReset(level->gameStateHandling, level->getPlayer()->getEpisodeNumber(), coinsLeft);
            level->gameStateHandling->stepsCount++;

            performResetIfNeeded(gameOver || reset);
        } else {
            if (renderGame) {
                this->window->close();
            }
            delete actions;
            delete this;
            return;
        }
    }
}

void Game::updateWindowEvents() {
    sf::Event e;

    while (this->window->pollEvent(e)) {
        if (e.Event::type == sf::Event::Closed) {
            this->window->close();
        }
    }
}

void Game::updatePlayerInput(char moveDirection, char shotDirection) {
    inputMovement(moveDirection);
    inputShooting(shotDirection);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        this->level->getPlayerFoV()->setDrawRays(!this->level->getPlayerFoV()->isDrawRaysSet());
    }
}

void Game::inputMovement(char direction) {
    if (direction == 'L') {
        this->level->movePlayer(-1.f, 0.f);
    }
    if (direction == 'R') {
        this->level->movePlayer(1.f, 0.f);
    }
    if (direction == 'U') {
        this->level->movePlayer(0.f, -1.f);
    }
    if (direction == 'D') {
        this->level->movePlayer(0.f, 1.f);
    }
}

void Game::inputShooting(char direction) {
    if (direction == 'L') {
        this->level->shot(-1.f, 0.f);
    }
    if (direction == 'R') {
        this->level->shot(1.f, 0.f);
    }
    if (direction == 'U') {
        this->level->shot(0.f, -1.f);
    }
    if (direction == 'D') {
        this->level->shot(0.f, 1.f);
    }
}

bool Game::playStep(char moveDirection, char shotDirection) {
    if (renderGame) {
        this->updateWindowEvents();
    }
    this->updatePlayerInput(moveDirection, shotDirection);
    if (renderGame) {
        this->updateLabels();
    }

    this->level->updateBullets();
    this->level->updateDangerMovement();
    this->level->calculateClosestObjectsDir();

    return this->level->gameStateHandling->gameOver;
}

void Game::render() {
    this->window->clear();

    this->level->renderGameObjects(*this->window);
    renderLabels();

    this->window->display();
}

void Game::performResetIfNeeded(bool reset) {
    if (reset) {
        int episodes_count = this->level->getPlayer()->getEpisodeNumber() + 1;
        int levelNum = level->getLevelNumber();
        delete this->level;

        if (levelNum == 9999) {
            levelNum = 0;
        }

        this->level = new Level(levelNum+1, MAP_SIZE);
        this->level->resetLevel();
        this->level->gameStateHandling->gameOver = false;
        this->level->getPlayer()->setEpisodes(episodes_count);
    }
}
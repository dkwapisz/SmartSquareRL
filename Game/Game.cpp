#include "Game.hpp"
#include <iostream>

Game::Game() {
    this -> initializeWindow();
    this -> initializeGameObjects();
    this -> initializePlayer();
    this -> initializeWalls();
}

Game::~Game() {
    delete this -> window;
    delete this -> player;

    for (auto &gameObject : this -> gameObjectsShape) {
        delete gameObject.second;
    }

    for (auto *bullet : this -> bullets) {
        delete bullet;
    }

    for (auto *wall : this -> walls) {
        delete wall;
    }
}

void Game::initializeWindow() {
    this -> window = new sf::RenderWindow(sf::VideoMode(600, 600),
                                          "SmartSquareRL",
                                          sf::Style::Close | sf::Style::Titlebar);
    this -> window -> setFramerateLimit(75);
    this -> window -> setVerticalSyncEnabled(false);
}

void Game::initializeGameObjects() {
    this -> gameObjectsShape["Bullet"] = new sf::RectangleShape();
    this -> gameObjectsShape["Wall"] = new sf::RectangleShape();
}

void Game::initializePlayer() {
    this -> player = new Player();
}

void Game::initializeWalls() {
    this -> walls.push_back(new Wall(this -> gameObjectsShape["Wall"], 60.f, 60.f));
}

void Game::run() {
    while (this -> window -> isOpen()) {
        this -> update();
        this -> render();
    }
}

void Game::updateBullets() {
    unsigned counter = 0;
    for (auto *bullet : this -> bullets) {
        bullet -> update();

        for (auto *wall : this -> walls) {
            if (bullet -> getBounds().intersects(wall -> getBounds())) {
                delete this -> bullets.at(counter);
                this -> bullets.erase(this -> bullets.begin() + counter);
                --counter;
            }
        }

        ++counter;
    }
}

void Game::updateWindowEvents() {
    sf::Event e;

    while (this -> window -> pollEvent(e)) {
        if (e.Event::type == sf::Event::Closed || e.Event::key.code == sf::Keyboard::Escape) {
            this -> window -> close();
        }
    }
}

void Game::updatePlayerInput() {
    inputMovement();
    inputShooting();
}

void Game::inputMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        this->player->movePlayer(-1.f, 0.f, walls);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        this->player->movePlayer(1.f, 0.f, walls);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        this->player->movePlayer(0.f, -1.f, walls);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        this->player->movePlayer(0.f, 1.f, walls);
    }
}

void Game::inputShooting() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        shot(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        shot(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        shot(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        shot(0.f, 1.f);
    }
}

void Game::shot(float directionX, float directionY) {
    if (player -> isShotPossible()) {
        float positionX = this -> player -> getCenterPosition() -> x - gameObjectsShape["Bullet"] -> getSize().x / 2;
        float positionY = this -> player -> getCenterPosition() -> y - gameObjectsShape["Bullet"] -> getSize().y / 2;

        this -> bullets.push_back(new Bullet(this -> gameObjectsShape["Bullet"],
                                             positionX, positionY,
                                             directionX, directionY,
                                             this -> player -> getShotSpeed()));
    } else {
        player -> incrementCooldown();
    }
}

void Game::update() {
    this -> updateWindowEvents();
    this -> updateBullets();
    this -> updatePlayerInput();
}

void Game::render() {
    this -> window -> clear();

    this -> player -> render(*this -> window);

    for (auto *bullet : this -> bullets) {
        bullet -> render(this -> window);
    }

    for (auto *wall : this -> walls) {
        wall -> render(this -> window);
    }

    this -> window -> display();
}

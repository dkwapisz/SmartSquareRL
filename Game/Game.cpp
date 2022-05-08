#include "Game.hpp"

Game::Game() {
    this -> initializeWindow();
    this -> initializePlayer();
}

Game::~Game() {
    delete this -> window;
    delete this -> player;
}

void Game::initializeWindow() {
    this -> window = new sf::RenderWindow(sf::VideoMode(800, 600),
                                          "SmartSquareRL",
                                          sf::Style::Close | sf::Style::Titlebar);
    this -> window -> setFramerateLimit(75);
    this -> window -> setVerticalSyncEnabled(false);
}

void Game::initializeGameObjects() {
    //TODO
}

void Game::initializePlayer() {
    this -> player = new Player();
}

void Game::run() {

    while (this -> window -> isOpen()) {
        this -> update();
        this -> render();
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        this -> player -> move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        this -> player -> move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        this -> player -> move(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        this -> player -> move(0.f, 1.f);
    }
}

void Game::update() {
    this->updateWindowEvents();
    this->updatePlayerInput();
}

void Game::render() {
    this -> window -> clear();

    this -> player -> render(*this -> window);

    this -> window -> display();
}

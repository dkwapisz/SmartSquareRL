#include "Game.hpp"

Game::Game() {
    this -> initializeWindow();
    this -> initializeGameObjects();
    this -> generateMap();
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

void Game::generateMap() {
    std::fstream mapFile;
    mapFile.open("..\\Game\\Maps\\test_map.txt");
    int mapSizeX = 20;
    int mapSizeY = 20;
    int number = 0;

    if (mapFile.is_open()) {
        for (int y = 0; y < mapSizeX; y++) {
            for (int x = 0; x < mapSizeY; x++) {
                mapFile >> number;

                if (number == 1) {
                    this -> walls.push_back(new Wall(this -> gameObjectsShape["Wall"],
                                                     30.f * x, 30.f * y));
                } else if (number == 9) {
                    this -> player = new Player(30.f * x, 30.f * y);
                }
            }
        }
    } else {
        std::cerr << "Could not open map file" << "\n";
    }

    mapFile.close();
}

void Game::run() {
    while (this -> window -> isOpen()) {
        this -> update();
        this -> render();
    }
}

void Game::updateBullets() {
    for (int i = 0; i < this -> bullets.size(); i++) {
        bullets[i] -> update();

        bool bullet_deleted = false;

        for (int j = 0; j < this -> walls.size() && !bullet_deleted; j++) {
            if (bullets[i] -> getBounds().intersects(walls[j] -> getBounds())) {

                delete this -> bullets[i];
                this -> bullets.erase(this -> bullets.begin() + i);

                bullet_deleted = true;
            }
        }
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

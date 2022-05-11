#include "Game.hpp"

Game::Game() {
    this -> initializeWindow();
    this -> initializeGameObjects();
    this -> coinsCount = 0;
    this -> generateMap();
}

Game::~Game() {
    delete this -> window;
    delete this -> player;

    for (auto &gameObject : this -> squareShapes) {
        delete gameObject.second;
    }

    for (auto *bullet : this -> bullets) {
        delete bullet;
    }

    for (auto *wall : this -> walls) {
        delete wall;
    }

    for (auto *box : this -> boxes) {
        delete box;
    }

    for (auto *staticDanger : this -> staticDangers) {
        delete staticDanger;
    }

    for (auto *coin : this -> coins) {
        delete coin;
    }

    for (auto *movingDanger : this -> movingDangers) {
        delete movingDanger;
    }

    for (auto *finish : this -> finishes) {
        delete finish;
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
    this -> squareShapes["Bullet"] = new sf::RectangleShape();
    this -> squareShapes["Wall"] = new sf::RectangleShape();
    this -> squareShapes["Box"] = new sf::RectangleShape();
    this -> squareShapes["StaticDanger"] = new sf::RectangleShape();
    this -> squareShapes["Finish"] = new sf::RectangleShape;
    this -> circleShapes["Coin"] = new sf::CircleShape();
    this -> circleShapes["MovingDanger"] = new sf::CircleShape();
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
                    this -> walls.push_back(new Wall(this -> squareShapes["Wall"],
                                                     30.f * x, 30.f * y));
                } else if (number == 2) {
                    this -> boxes.push_back(new Box(this -> squareShapes["Box"],
                                                     30.f * x, 30.f * y));
                } else if (number == 3) {
                    this -> staticDangers.push_back(new StaticDanger(this -> squareShapes["StaticDanger"],
                                                                     30.f * x, 30.f * y));
                } else if (number == 4) {
                    this -> coins.push_back(new Coin(this -> circleShapes["Coin"],
                                                    30.f * x, 30.f * y));
                    coinsCount++;
                } else if (number == 5) {
                    this -> movingDangers.push_back(new MovingDanger(this -> circleShapes["MovingDanger"],
                                                    30.f * x, 30.f * y, true));
                } else if (number == 6) {
                    this -> movingDangers.push_back(new MovingDanger(this -> circleShapes["MovingDanger"],
                                                    30.f * x, 30.f * y, false));
                } else if (number == 7) {
                    this -> finishes.push_back(new Finish(this -> squareShapes["Finish"],
                                                                     30.f * x, 30.f * y));
                }
                else if (number == 9) {
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
        bool box_deleted = false;

        for (int j = 0; j < this -> walls.size() && !bullet_deleted; j++) {
            if (bullets[i] -> getBounds().intersects(walls[j] -> getBounds())) {

                delete this -> bullets[i];
                this -> bullets.erase(this -> bullets.begin() + i);

                bullet_deleted = true;
            }
        }

        for (int j = 0; j < this -> boxes.size() && !bullet_deleted && !box_deleted; j++) {
            if (bullets[i] -> getBounds().intersects(boxes[j] -> getBounds())) {

                delete this -> bullets[i];
                this -> bullets.erase(this -> bullets.begin() + i);

                bullet_deleted = true;

                delete this -> boxes[j];
                this -> boxes.erase(this -> boxes.begin() + j);

                box_deleted = true;
            }
        }

        for (int j = 0; j < staticDangers.size() && !bullet_deleted; j++) {
            if (bullets[i] -> getBounds().intersects(staticDangers[j] -> getBounds())) {
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
        movePlayer(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        movePlayer(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        movePlayer(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        movePlayer(0.f, 1.f);
    }
}

void Game::movePlayer(float directionX, float directionY) {
    float startPosX = player -> getPosX();
    float startPosY = player -> getPosY();

    this -> player -> movePlayer(directionX, directionY);

    if (checkCollision()) {
        this -> player -> setPosition(startPosX, startPosY);
    }
}

bool Game::checkCollision() {
    for (const auto& wall : walls) {
        if (wall -> getBounds().intersects(this -> player -> getBounds())) {
            return true;
        }
    }

    for (const auto& box : boxes) {
        if (box -> getBounds().intersects(this -> player -> getBounds())) {
            return true;
        }
    }

    for (const auto& staticDanger : staticDangers) {
        if (staticDanger -> getBounds().intersects(this -> player -> getBounds())) {
            this -> player -> resetPosition();
            return false;
        }
    }

    for (const auto& finish : finishes) {
        if (finish -> getBounds().intersects(this -> player -> getBounds())) {
            this -> finishLevel();
            return false;
        }
    }

    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] -> getBounds().intersects(this -> player -> getBounds())) {
            delete coins[i];
            coins.erase(coins.begin() + i);
            this -> player -> addCoin();
        }
    }

    return false;
}

void Game::updateDangerMovement() {
    for (auto *movingDanger : this -> movingDangers) {
        checkDangerCollision(movingDanger);
        movingDanger -> move();
    }
}

void Game::checkDangerCollision(MovingDanger *movingDanger) {
    if (movingDanger -> getBounds().intersects(this -> player -> getBounds())) {
        this -> player -> resetPosition();
    }

    for (auto *wall : this -> walls) {
        if (movingDanger -> getBounds().intersects(wall -> getBounds())) {
            movingDanger -> reverseDirection();
        }
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
        float positionX = this -> player -> getCenterPosition() -> x - squareShapes["Bullet"] -> getSize().x / 2;
        float positionY = this -> player -> getCenterPosition() -> y - squareShapes["Bullet"] -> getSize().y / 2;

        this -> bullets.push_back(new Bullet(this -> squareShapes["Bullet"],
                                             positionX, positionY,
                                             directionX, directionY,
                                             this -> player -> getShotSpeed()));
    } else {
        player -> incrementCooldown();
    }
}

bool Game::checkPlayerCoins() {
    return this -> coinsCount == this -> player -> getPlayerCoins();
}

void Game::update() {
    this -> updateWindowEvents();
    this -> updateBullets();
    this -> updatePlayerInput();
    this -> updateDangerMovement();
}

void Game::render() {
    this -> window -> clear();

    for (auto *finish : this -> finishes) {
        finish -> render(this -> window);
    }

    this -> player -> render(*this -> window);

    for (auto *bullet : this -> bullets) {
        bullet -> render(this -> window);
    }

    for (auto *wall : this -> walls) {
        wall -> render(this -> window);
    }

    for (auto *box : this -> boxes) {
        box -> render(this -> window);
    }

    for (auto *staticDanger : this -> staticDangers) {
        staticDanger -> render(this -> window);
    }

    for (auto *coin : this -> coins) {
        coin -> render(this -> window);
    }

    for (auto *movingDanger : this -> movingDangers) {
        movingDanger -> render(this -> window);
    }

    this -> window -> display();
}

void Game::finishLevel() {
    if (this -> checkPlayerCoins()) {
        std::cout << "Player wins! \n";
    }
}

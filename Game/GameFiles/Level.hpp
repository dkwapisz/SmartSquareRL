#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "GameObjects/Player.hpp"
#include "GameObjects/Bullet.hpp"
#include "GameObjects/Wall.hpp"
#include "GameObjects/Box.hpp"
#include "GameObjects/StaticDanger.hpp"
#include "GameObjects/Coin.hpp"
#include "GameObjects/MovingDanger.hpp"
#include "GameObjects/Finish.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include <fstream>
#include <cmath>

class Level {

private:
    std::map<std::string, sf::RectangleShape *> squareShapes;
    std::map<std::string, sf::CircleShape *> circleShapes;
    std::vector<Bullet *> bullets;
    std::vector<Wall *> walls;
    std::vector<Box *> boxes;
    std::vector<StaticDanger *> staticDangers;
    std::vector<Coin *> coins;
    std::vector<MovingDanger *> movingDangers;
    std::vector<Finish *> finishes;

    std::map<int, std::string> mapPath;

    Player *player;
    sf::Clock *clock;

    int coinsCount;
    int playerCoinsCount;
    int levelNumber;
    bool levelFinished;

    bool closestObstacleBox;
    char closestObstacleDir;
    char closestCoinDir;
    char closestEnemyDir;
    char finishDir;

    void initializeMapPaths();
    void initializeLevelAttributes(int levelNr);
    void initializeGameObjects();
    void generateMap();
    bool checkCollision();
    void resetLevel();
    void checkDangerCollision(MovingDanger *movingDanger);

    void calculateClosestObstacleDir();
    void calculateClosestEnemyDir();
    void calculateClosestCoinDir();
    void calculateFinishDirectionDir();

public:
    Level();
    explicit Level(int levelNumber);
    virtual ~Level();

    bool isLevelFinished() const;
    void movePlayer(float directionX, float directionY);
    void shot(float directionX, float directionY);
    void updateBullets();
    void updateDangerMovement();
    void renderGameObjects(sf::RenderTarget &target);

    int getClockTime() const;
    Player *getPlayer() const;
    int getCoinsCount() const;
    int getPlayerCoinsCount() const;
    int getLevelNumber() const;
    int getMapsCount() const;

    // gRPC message
    bool isClosestObstacleBox();
    int32_t getCoinsNeeded();
    char getClosestObstacleDir();
    char getClosestCoinDir();
    char getClosestEnemyDir();
    char getFinishDirectionDir();
    // --------
    void calculateClosestObjectsDir();
};


#endif //LEVEL_HPP

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../GameStateHandling.hpp"

class PlayerFoV {
private:
    int numberOfRays;
    bool drawRays;
    bool coinInView;
    bool finishInView;
    float *rayVertexes;
    float getRadians(float degree);
    Coin *closestCoin;
    Wall *lastDiscoveredWall;

public:
    PlayerFoV(int numberOfRays, bool drawRays);
    void calculateRays(std::vector<Wall *> *walls, std::vector<Box *> *boxes, std::vector<Coin *> *coins,
                       std::vector<Finish *> *finishes, float playerX, float playerY,
                       GameStateHandling *gameStateHandling);
    void render(sf::RenderTarget &target, float playerX, float playerY);

    bool isCoinInView() const;
    void setCoinInView(bool coinInView);

    bool isFinishInView() const;
    void setFinishInView(bool finishInView);

    bool isDrawRaysSet() const;
    void setClosestCoin(std::map<Coin*, float> *coinDistances);
    Coin* getClosestCoin();
    void setDrawRays(bool setDrawRays);

    Wall *getLastDiscoveredWall() const;
};

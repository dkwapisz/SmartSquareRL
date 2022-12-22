// Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
// License:      GPLv3

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../GameStateHandling.hpp"
#include "Floor.hpp"

class PlayerFoV {
private:
    int numberOfRays;
    bool drawRays;
    bool coinInView;
    bool finishInView;
    float *rayVertexes;

    float getRadians(float degree);

    Coin *closestCoin;

public:
    PlayerFoV(int numberOfRays, bool drawRays);

    void calculateRays(std::vector<Wall *> *walls, std::vector<Box *> *boxes, std::vector<Coin *> *coins,
                       std::vector<Finish *> *finishes, std::vector<Floor *> *floors, float playerX, float playerY);

    void render(sf::RenderTarget &target, float playerX, float playerY);

    bool isCoinInView() const;

    void setCoinInView(bool coinInView);

    bool isFinishInView() const;

    void setFinishInView(bool finishInView);

    bool isDrawRaysSet() const;

    void setClosestCoin(std::map<Coin *, float> *coinDistances);

    Coin *getClosestCoin();

    void setDrawRays(bool setDrawRays);

    float* getRayVertexes() const;

    int getNumberOfRays() const;
};

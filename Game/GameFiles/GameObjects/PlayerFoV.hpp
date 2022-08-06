#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

class PlayerFoV {
private:
    int numberOfRays;
    bool drawRays;
    bool coinInView;
    float *rayVertexes;
    float getRadians(float degree);

public:
    PlayerFoV(int numberOfRays, bool drawRays);
    void calculateRays(std::vector<Wall *> *walls, std::vector<Box *> *boxes, std::vector<Coin *> *coins,
                       float playerX, float playerY);
    void render(sf::RenderTarget &target, float playerX, float playerY);

    bool isCoinInView() const;
    void setCoinInView(bool coinInView);
    bool isDrawRaysSet() const;

};

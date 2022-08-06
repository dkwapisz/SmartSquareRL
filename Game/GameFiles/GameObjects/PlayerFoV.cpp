#include "PlayerFoV.hpp"

PlayerFoV::PlayerFoV(int numberOfRays, bool drawRays) {
    this -> drawRays = drawRays;
    this -> numberOfRays = numberOfRays;

    // Element n -> x, n+1 -> y
    this -> rayVertexes = new float[numberOfRays * 2];
    this -> coinInView = false;
}

void PlayerFoV::calculateRays(std::vector<Wall *> *walls, std::vector<Box *> *boxes, std::vector<Coin *> *coins,
                              float playerX, float playerY) {
    float dirX, dirY, vertexX, vertexY;
    int arrayIterator = 0;
    int fullAngle = 360;

    for (int i = 0; i < fullAngle; i += fullAngle / numberOfRays) {
        float angleRad = getRadians((float) i);
        dirX = std::cos(angleRad);
        dirY = std::sin(angleRad);

        int mapX = (int) playerX;
        int mapY = (int) playerY;

        int stepX, stepY;
        float sideDistX, sideDistY, perpWallDist;

        float deltaDistX = std::abs(1 / dirX);
        float deltaDistY = std::abs(1 / dirY);

        int hit = 0;
        int side;

        if (dirX < 0) {
            stepX = -1;
        } else {
            stepX = 1;
        }
        if (dirY < 0) {
            stepY = -1;
        } else {
            stepY = 1;
        }

        sideDistX = deltaDistX;
        sideDistY = deltaDistY;

        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            for (const auto& wall : *walls) {
                if (wall -> getBounds().contains(sf::Vector2f(mapX, mapY))) {
                    hit = 1;
                }
            }

            for (const auto& box : *boxes) {
                if (box -> getBounds().contains(sf::Vector2f(mapX, mapY))) {
                    hit = 1;
                }
            }

            for (const auto& coin : *coins) {
                if (coin -> getBounds().contains(sf::Vector2f(mapX, mapY))) {
                    coinInView = true;
                    break;
                }
            }
        }

        if (side == 0) {
            perpWallDist = (mapX - playerX + (float) (1 - stepX) / 2) / dirX;
        } else {
            perpWallDist = (mapY - playerY + (float) (1 - stepY) / 2) / dirY;
        }

        vertexX = playerX + dirX * perpWallDist;
        vertexY = playerY + dirY * perpWallDist;

        rayVertexes[arrayIterator] = vertexX;
        rayVertexes[arrayIterator + 1] = vertexY;

        arrayIterator += 2;
    }
}

void PlayerFoV::render(sf::RenderTarget &target, float playerX, float playerY) {
    auto *line = new sf::Vertex[2];
    int arrayIterator = 0;
    for (int i = 0; i < numberOfRays; i++) {
        line[0] = sf::Vertex(sf::Vector2f(playerX, playerY));
        line[1] = sf::Vertex(sf::Vector2f(rayVertexes[arrayIterator], rayVertexes[arrayIterator + 1]));
        target.draw(line, 2, sf::Lines);
        arrayIterator += 2;
    }
}

float PlayerFoV::getRadians(float degree) {
    float pi = 3.14159265359f;
    return (degree * (pi / 180));
}

bool PlayerFoV::isCoinInView() const {
    return coinInView;
}

void PlayerFoV::setCoinInView(bool coinInView) {
    PlayerFoV::coinInView = coinInView;
}

bool PlayerFoV::isDrawRaysSet() const {
    return drawRays;
}

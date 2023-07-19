//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_ENEMY_H
#define MONPROJETSDL_ENEMY_H

#include <SDL2/SDL.h>
#include "GameObject.h"
#include "math.h"

class Enemy : public GameObject {
private:
    bool isActive = true;

    hmg::Vector2D position;
    hmg::Vector2D velocity;
    hmg::Vector2D acceleration;

    float angle;
    float radius;
    float maxForce;
    float maxSpeed;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
public:
    Enemy(SDL_Renderer *renderer, const char *spriteFilePath, hmg::Vector2D *startingScreenPosition, float width,float height, double angle);
    void update() override;
    void updatePos();
    void draw() override;
    void wrapAround();

    //flocking ai
    void run(Enemy** listEnemies, int numberOfEnemies);
    void applyForce(hmg::Vector2D force);
    void flockTogether(Enemy** listEnemies, int numberOfEnemies);
    hmg::Vector2D seek(hmg::Vector2D& target);

    void setDeltaTime();
    float getRadius();
    void setIsActive(bool b);
    bool getIsActive();
};


#endif //MONPROJETSDL_ENEMY_H

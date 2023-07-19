//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_BULLETS_H
#define MONPROJETSDL_BULLETS_H

#include "GameObject.h"
#include "math.h"
#include "Enemy.h"

class Bullets : public GameObject {
private:
    bool isActive;

    float rayon;
    float velocity;
    float speed;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    float deltaTime = 0;
public:
    Bullets(SDL_Renderer *renderer, const char *spriteFilePath, hmg::Vector2D startingScreenPosition, float width, float height);
    void draw() override;
    void update() override;
    void moveBullet();
    void checkIfActive();

    void setDeltaTime();
    void setIsActive(bool b);
    bool getIsActive();
    float getRadius();
};


#endif //MONPROJETSDL_BULLETS_H

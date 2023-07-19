//
// Created by isi on 1/16/2023.
//

#ifndef SPACE_INVADERS_EXPLOSION_H
#define SPACE_INVADERS_EXPLOSION_H

#include "GameObject.h"
#include "math.h"
#include "SoundManager.h"

class Explosion : public GameObject{
private:
    bool isActive = true;
    SDL_Rect imagePosition;
    SoundManager* soundManager = nullptr;

    int col, row, animationTime;
    Uint32 lastMoveSprite = SDL_GetTicks();
    int deltaTime = 50;
public:
    Explosion(SDL_Renderer *renderer, const char *spriteFilePath, hmg::Vector2D *startingScreenPosition, float width, float height);
    void update() override;
    void draw() override;
    void endExplosion();
    bool getIsActive();
};


#endif //SPACE_INVADERS_EXPLOSION_H

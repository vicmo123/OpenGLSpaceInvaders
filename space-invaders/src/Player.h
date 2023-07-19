//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_PLAYER_H
#define MONPROJETSDL_PLAYER_H

#include "GameObject.h";
#include "Input.h"
#include "gameDefine.h"
#include "PhysicsMove.h"
#include "BulletManager.h"
#include "SoundManager.h"

class Player : GameObject {
private:
    PhysicsMove* movementManager = nullptr;
    BulletManager* bulletManager = nullptr;
    SoundManager* soundManager = nullptr;

    Uint32 lastShoot = SDL_GetTicks();
    int deltaTime = 100;
public:
    Player(SDL_Renderer *renderer, hmg::Vector2D startingScreenPosition, float width, float height, const char *spriteFilePath);
    void draw() override;
    void update() override;
};


#endif //MONPROJETSDL_PLAYER_H

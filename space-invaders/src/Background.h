//
// Created by isi on 1/16/2023.
//

#ifndef SPACE_INVADERS_BACKGROUND_H
#define SPACE_INVADERS_BACKGROUND_H

#include <SDL2/SDL_image.h>
#include "Singleton.h"
#include "math.h"
#include "gameDefine.h"

class Background : public Singleton<Background> {
private:
    SDL_Texture* backGround;
    float velocity;
    float speed;
    SDL_Rect imagePosition;

    SDL_Renderer* renderer;
    int mapWidth, mapHeight;

    Uint32 lastShoot = SDL_GetTicks();
    int deltaTime = 25;
public:
    void init(SDL_Renderer* renderer, int mapWidth, int mapHeight);
    void update();
    void draw();
};

#endif //SPACE_INVADERS_BACKGROUND_H

//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_GAMEOBJECT_H
#define MONPROJETSDL_GAMEOBJECT_H

#include <SDL2/SDL.h>
#include "math.h"
#include "Shape.h"
#include "Sprite.h"
#include "Input.h"

class GameObject {
private:
    SDL_Renderer* renderer;
    Shape* shape = nullptr;
    Sprite* sprite = nullptr;

public:
    Input* input;
    GameObject(SDL_Renderer* renderer, const char* spriteFilePath, hmg::Vector2D* startingScreenPosition, float width, float height);
    virtual void draw() = 0;
    virtual void update() = 0;

    SDL_Renderer* getRenderer();
    Sprite* getSprite();
    Shape* getShape();
};


#endif //MONPROJETSDL_GAMEOBJECT_H

//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_SPRITE_H
#define MONPROJETSDL_SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Sprite {
private:
    const char *filePath;
    SDL_Texture* sprite;
    int spriteWidth, spriteHeight;

public:
    Sprite(SDL_Renderer* renderer, const char* filePath);
    SDL_Texture* generateTexture(SDL_Renderer* renderer, const char* filePath);
    void getSpriteData();

    //Getters
    SDL_Texture *getSprite() const;
    int getSpriteWidth() const;
    int getSpriteHeight() const;

    //Setters
    void setSprite(SDL_Texture *img);
    void setSpriteWidth(int spriteWidth);
    void setSpriteHeight(int spriteHeight);
};


#endif //MONPROJETSDL_SPRITE_H

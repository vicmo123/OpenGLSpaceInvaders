//
// Created by isi on 1/10/2023.
//

#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, const char* filePath) : filePath(filePath) {
    this->setSprite(this->generateTexture(renderer, filePath));
    this->getSpriteData();
}

SDL_Texture* Sprite::generateTexture(SDL_Renderer* renderer, const char* filePath) {
    this->filePath = filePath;

    SDL_Texture* newTexture = IMG_LoadTexture(renderer,this->filePath);
    if(newTexture == nullptr){
        std::cout << this->filePath << std::endl;
        SDL_Log("Sprite loading issue occured");
    }

    return newTexture;
}

void Sprite::getSpriteData() {
    SDL_QueryTexture(sprite, nullptr, nullptr, &this->spriteWidth,&this->spriteHeight);
}

SDL_Texture *Sprite::getSprite() const {
    return sprite;
}

int Sprite::getSpriteWidth() const {
    return spriteWidth;
}

int Sprite::getSpriteHeight() const {
    return spriteHeight;
}

void Sprite::setSprite(SDL_Texture *img) {
    Sprite::sprite = img;
}

void Sprite::setSpriteWidth(int spriteWidth) {
    Sprite::spriteWidth = spriteWidth;
}

void Sprite::setSpriteHeight(int spriteHeight) {
    Sprite::spriteHeight = spriteHeight;
}



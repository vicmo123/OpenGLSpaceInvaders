//
// Created by isi on 1/16/2023.
//

#include "Explosion.h"

Explosion::Explosion(SDL_Renderer *renderer, const char *spriteFilePath, hmg::Vector2D *startingScreenPosition, float width, float height) : GameObject(renderer, spriteFilePath, startingScreenPosition, width, height) {
    col = 0;
    row = 0;
    int spriteWidth, spriteHeight;
    SDL_QueryTexture(this->getSprite()->getSprite(), 0, 0, &spriteWidth, &spriteHeight);
    imagePosition = {0, 0, static_cast<int>(spriteWidth / 5.0f), static_cast<int>(spriteHeight / 2)};
    imagePosition.x = col * imagePosition.w;
    imagePosition.y = row * imagePosition.h;
    this->getShape()->setShapeFloat(new SDL_FRect{startingScreenPosition->x, startingScreenPosition->y, static_cast<float>(imagePosition.w), static_cast<float>(imagePosition.h)});
    animationTime = 100;
    lastMoveSprite = SDL_GetTicks();

    soundManager->getInstance().playWav(2, 1, 0);
}

void Explosion::update() {
    if (SDL_GetTicks() - lastMoveSprite > deltaTime) {
        imagePosition.y = row * imagePosition.h;
        if (SDL_GetTicks() - lastMoveSprite >= animationTime) {
            col++;
            if(col >= 6){
                row++;
            }

            imagePosition.x = col * imagePosition.w;
            lastMoveSprite = SDL_GetTicks();
        }

        if(col >= 6 && row >= 2){
            endExplosion();
        }
    }
}

void Explosion::draw() {
    SDL_RenderCopyF(getRenderer(), this->getSprite()->getSprite(), &imagePosition, getShape()->getShapeFloat());
}

void Explosion::endExplosion() {
    isActive = false;
}

bool Explosion::getIsActive() {
    return isActive;
}

//
// Created by isi on 1/10/2023.
//

#include "Bullets.h"

Bullets::Bullets(SDL_Renderer *renderer, const char *spriteFilePath, hmg::Vector2D startingScreenPosition, float width, float height) : GameObject(renderer, spriteFilePath, &startingScreenPosition, width, height) {
    this->velocity = 1.0f;
    this->speed = 1.0f;

    this->rayon = getShape()->getShapeFloat()->w / 2;

    isActive = true;
}

void Bullets::draw() {
    SDL_Rect bulletZone{(getSprite()->getSpriteWidth() / 2 - 11), (getSprite()->getSpriteHeight() / 2 - 21), 30, 30};
    //SDL_SetRenderDrawColor(getRenderer(), 255, 0 , 0, 255);
    //SDL_RenderDrawRectF(getRenderer(), getShape()->getShapeFloat());
    SDL_RenderCopyF(getRenderer(), this->getSprite()->getSprite(), &bulletZone, getShape()->getShapeFloat());
}

void Bullets::update() {
    moveBullet();
    checkIfActive();
}

void Bullets::moveBullet() {
    setDeltaTime();

    this->getShape()->setShapeFloat(new SDL_FRect{this->getShape()->getShapeFloat()->x, this->getShape()->getShapeFloat()->y - velocity  * speed * deltaTime, this->getShape()->getShapeFloat()->w, this->getShape()->getShapeFloat()->h});
}

void Bullets::checkIfActive() {
    if (this->getShape()->getShapeFloat()->x > 800.0f || this->getShape()->getShapeFloat()->y > 600.0f || this->getShape()->getShapeFloat()->x < 0.0f || this->getShape()->getShapeFloat()->y < 0.0f) {
        isActive = false;
    }
}

void Bullets::setDeltaTime() {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );
}

void Bullets::setIsActive(bool b) {
    this->isActive = b;
}

bool Bullets::getIsActive() {
    return isActive;
}

float Bullets::getRadius() {
    return this->rayon;
}

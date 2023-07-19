//
// Created by isi on 1/10/2023.
//

#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer, const char* spriteFilePath, hmg::Vector2D* startingScreenPosition, float width, float height) {
    this->renderer = renderer;

    if(spriteFilePath != nullptr){
        this->sprite = new Sprite(this->renderer, spriteFilePath);
    }

    this->shape = new Shape(startingScreenPosition->x, startingScreenPosition->y, width, height);
}

SDL_Renderer* GameObject::getRenderer() {
    return this->renderer;
}

Sprite* GameObject::getSprite() {
    return this->sprite;
}

Shape* GameObject::getShape() {
    return this->shape;
}

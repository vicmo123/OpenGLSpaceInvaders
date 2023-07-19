//
// Created by isi on 1/10/2023.
//

#include "Player.h"

Player::Player(SDL_Renderer* renderer, hmg::Vector2D startingScreenPosition,float width, float height, const char *spriteFilePath) : GameObject(renderer, spriteFilePath, &startingScreenPosition, width, height) {
    this->movementManager = new PhysicsMove(1.0f, hmg::bounds2D{WIDTH, HEIGHT}, this->getShape(), KeyType::AWSD, new Direction[4]{Direction::LEFT, Direction::RIGHT, Direction::NO_DIRECTION, Direction::NO_DIRECTION}, true);
    lastShoot = SDL_GetTicks();

    this->bulletManager->getInstance();
}

void Player::update() {
    this->movementManager->update();

    if(input->getInstance().checkSpaceBar()){
        if (SDL_GetTicks() - lastShoot >= deltaTime) {
            this->bulletManager->getInstance().addBullet(getRenderer(), hmg::Vector2D{getShape()->getShapeFloat()->x + (getShape()->getShapeFloat()->w / 2 - 15),getShape()->getShapeFloat()->y});
            lastShoot = SDL_GetTicks();

            soundManager->getInstance().playWav(1, 0, 0);
        }
    }
}

void Player::draw() {
    SDL_RenderCopyF(getRenderer(), this->getSprite()->getSprite(), nullptr, getShape()->getShapeFloat());
}
//
// Created by isi on 1/10/2023.
//

#include "PlayerManager.h"

void PlayerManager::init(SDL_Renderer *renderer, hmg::Vector2D startingScreenPosition,float width, float height, const char *spriteFilePath) {
    this->setInitialPosition(&startingScreenPosition);
    this->setPlayerSize(new hmg::Vector2D{width, height});

    this->player = new Player(renderer, *this->initialPosition, playerSize->x, playerSize->y, spriteFilePath);
}

void PlayerManager::setPlayerSize(hmg::Vector2D *playerSize) {
    this->playerSize = playerSize;
}

void PlayerManager::setInitialPosition(hmg::Vector2D *initialPosition) {
    this->initialPosition = initialPosition;
}

Player *PlayerManager::getPlayer() const {
    return this->player;
}

void PlayerManager::setPlayer(Player *player) {
    this->player = player;
}

const hmg::Vector2D &PlayerManager::getPlayerSize() const {
    return *this->playerSize;
}

const hmg::Vector2D &PlayerManager::getInitialPosition() const {
    return *this->initialPosition;
}

void PlayerManager::draw() {
    this->player->draw();
}

void PlayerManager::update() {
    this->player->update();
}

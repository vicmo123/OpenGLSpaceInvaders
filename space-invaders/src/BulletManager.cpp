//
// Created by isi on 1/10/2023.
//

#include "BulletManager.h"

void BulletManager::init(SDL_Renderer* renderer){
    this->renderer = renderer;
    this->tabBulletsPlayer = new Bullets * [20]();
}

void BulletManager::addBullet(SDL_Renderer* renderer, hmg::Vector2D pos) {
    if (this->nbBullets < 20) {
        this->tabBulletsPlayer[this->nbBullets] = new Bullets(this->renderer, BULLET_SPRITE, hmg::Vector2D{pos.x, pos.y}, 25.0f, 25.0f );

        this->nbBullets++;
    }
}

void BulletManager::deleteInnactiveBullets() {
    for (int i = 0; i < this->nbBullets; i++) {
        if (tabBulletsPlayer[i]->getIsActive() == false) {
            delete this->tabBulletsPlayer[i];
            this->tabBulletsPlayer[i] = this->tabBulletsPlayer[this->nbBullets - 1];
            this->nbBullets--;
            i--;
        }
    }
}

void BulletManager::checkCollisionWithEnemies(Bullets* bullet, Enemy* enemy) {
    hmg::Vector2D a = hmg::Vector2D{bullet->getShape()->getShapeFloat()->x, bullet->getShape()->getShapeFloat()->y};
    hmg::Vector2D b = hmg::Vector2D{enemy->getShape()->getShapeFloat()->x, enemy->getShape()->getShapeFloat()->y};
    hmg::Vector2D aTob = hmg::Vector2D::Sub(b, a);

    if (aTob.GetMagnitude() <= enemy->getRadius() + bullet->getRadius()) {
        enemy->setIsActive(false);
        std::cout << "collision" << std::endl;

        bullet->setIsActive(false);
    }
}

void BulletManager::update(Enemy** listEnemies, int numberOfEnemies) {
    this->deleteInnactiveBullets();

    for (int i = 0; i < this->nbBullets; i++) {
        tabBulletsPlayer[i]->update();

        for (int j = 0; j < numberOfEnemies; j++) {
            checkCollisionWithEnemies(tabBulletsPlayer[i], listEnemies[j]);
            if(tabBulletsPlayer[i]->getIsActive() == false){
                break;
            }
        }
    }
}

void BulletManager::draw() {
    for (int i = 0; i < this->nbBullets; i++) {
        tabBulletsPlayer[i]->draw();
    }
}





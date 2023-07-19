//
// Created by isi on 1/10/2023.
//

#include "EnemyManager.h"
#include "gameDefine.h"

const double TWO_PI = 6.28318530718;

void EnemyManager::init(SDL_Renderer* renderer) {
    this->renderer = renderer;

    distribution = std::uniform_real_distribution<double> (0.0, TWO_PI);
    enemiesList = new Enemy * [5]();
    explosionTab = new Explosion * [5]();

    for (int i = 0; i < 5; ++i) {
        spawnEnemy(60.0f, 45.0f, ALIEN_SPRITE);
    }
}

void EnemyManager::spawnEnemy(float width, float height, const char *spriteFilePath) {


    if (this->numberOfEnemies < 5) {
        hmg::Vector2D spawnLocation = getValidSpot();
        this->enemiesList[this->numberOfEnemies] = new Enemy(renderer, spriteFilePath, &spawnLocation, 60.0f, 45.0f, distribution(generator));

        this->numberOfEnemies++;
    }
}

void EnemyManager::removeEnemy() {
    for (int i = 0; i < this->numberOfEnemies; i++) {
        if (enemiesList[i]->getIsActive() == false) {
            startExplosion(new hmg::Vector2D{ enemiesList[i]->getShape()->getShapeFloat()->x, enemiesList[i]->getShape()->getShapeFloat()->y }, 50, 50);
            this->scoreManager->getInstance().addPoints(100);
            delete this->enemiesList[i];
            this->enemiesList[i] = this->enemiesList[this->numberOfEnemies - 1];
            this->numberOfEnemies--;
            i--;
        }
    }

    for (int j = 0; j < this->numberOfExplosion; j++) {
        if(explosionTab[j] != nullptr){
            if (explosionTab[j]->getIsActive() == false) {
                delete this->explosionTab[j];
                this->explosionTab[j] = this->explosionTab[this->numberOfExplosion - 1];
                this->numberOfExplosion--;
                j--;
            }
        }
    }
}

const hmg::Vector2D &EnemyManager::getEnemySize() const {
    return *this->enemySize;
}

void EnemyManager::setEnemySize(hmg::Vector2D *enemySize) {
    this->enemySize = enemySize;
}

void EnemyManager::run() {
    //if dead will delete the dead one and add a new one
    removeEnemy();
    spawnEnemy(60.0f, 45.0f, ALIEN_SPRITE);

    for (int i = 0; i < numberOfEnemies; i++) {
        enemiesList[i]->run(enemiesList, numberOfEnemies);
    }

    for(int i = 0; i < numberOfExplosion; i++){
        if(explosionTab[i] != nullptr){
            explosionTab[i]->update();
        }
    }
}

void EnemyManager::render() {
    for (int i = 0; i < numberOfEnemies; i++) {
        enemiesList[i]->draw();
    }

    for(int i = 0; i < numberOfExplosion; i++){
        if(explosionTab[i] != nullptr){
            explosionTab[i]->draw();
        }
    }
}

Enemy **EnemyManager::getEnemiesList() const {
    return enemiesList;
}

int EnemyManager::getNumEnemies() {
    return numberOfEnemies;
}

void EnemyManager::startExplosion(hmg::Vector2D* startPos, float width, float height) {
    if(numberOfExplosion < 5){
        explosionTab[numberOfExplosion] = new Explosion(renderer, "assets/sprites/ExplosionSprite.png", startPos, width, height);
        this->numberOfExplosion++;
    }
}

hmg::Vector2D EnemyManager::getValidSpot()
{
    bool spotFound = false;
    hmg::Vector2D validSpot;

    if(numberOfEnemies > 0){
        for (int i = 0; i < 50; i++)
        {
            float x = hmg::randomNumber::generateNumberF(MIN_RAND, MAX_RAND_X);
            float y = hmg::randomNumber::generateNumberF(MIN_RAND, MAX_RAND_Y);

            hmg::Vector2D spotInMap = hmg::Vector2D{x, y};

            for (int j = 0; j < numberOfEnemies; ++j) {
                if (intersectRect(new SDL_Rect{static_cast<int>(enemiesList[j]->getShape()->getShapeFloat()->x), static_cast<int>(enemiesList[j]->getShape()->getShapeFloat()->y), static_cast<int>(enemiesList[j]->getShape()->getShapeFloat()->w), static_cast<int>(enemiesList[j]->getShape()->getShapeFloat()->y)} , new SDL_Rect{static_cast<int>(x), static_cast<int>(y), 60, 45}) == false)
                {
                    validSpot = spotInMap;
                    spotFound = true;
                }
            }
        }
    }

    if(spotFound == true){
        return validSpot;
    }
    else{
        return hmg::Vector2D{0,0};
    }
}

bool EnemyManager::intersectRect(const SDL_Rect * r1, const SDL_Rect * r2) {
    return !(r2->x > (r1->x + r1->w) ||
             (r2->x + r2->w) < r1->x ||
             r2->y > (r1->y + r1->h) ||
             (r2->y + r2->h) < r1->y);
}

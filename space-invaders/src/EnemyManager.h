//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_ENEMYMANAGER_H
#define MONPROJETSDL_ENEMYMANAGER_H

#include "Singleton.h"
#include "math.h"
#include "Enemy.h"
#include <vector>
#include <random>
#include "Explosion.h"
#include "ScoreManager.h"

class EnemyManager : public Singleton<EnemyManager> {
private:
    SDL_Renderer* renderer;
    ScoreManager* scoreManager;

    int numberOfEnemies = 0;
    int numberOfExplosion = 0;
    hmg::Vector2D *enemySize = nullptr;
    Enemy** enemiesList;
    Explosion** explosionTab;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;

public:
    void init(SDL_Renderer* renderer);
    void spawnEnemy(float width, float height, const char *spriteFilePath);
    void startExplosion(hmg::Vector2D* startPos, float width, float height);
    void removeEnemy();

    const hmg::Vector2D &getEnemySize() const;
    void setEnemySize(hmg::Vector2D *enemySize);
    Enemy **getEnemiesList() const;
    int getNumEnemies();

    void run();
    void render();


    hmg::Vector2D getValidSpot();
    bool intersectRect(const SDL_Rect * r1, const SDL_Rect * r2);
};


#endif //MONPROJETSDL_ENEMYMANAGER_H

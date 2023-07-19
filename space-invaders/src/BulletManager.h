//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_BULLETMANAGER_H
#define MONPROJETSDL_BULLETMANAGER_H

#include "Singleton.h"
#include <SDL2/SDL.h>
#include "Bullets.h"
#include "gameDefine.h"

class BulletManager : public Singleton<BulletManager> {
private:
    SDL_Renderer* renderer;

    Bullets** tabBulletsPlayer;
    int nbBullets;
public :
    void init(SDL_Renderer* renderer);
    void addBullet(SDL_Renderer* renderer, hmg::Vector2D pos);
    void deleteInnactiveBullets();
    void checkCollisionWithEnemies(Bullets* bullet, Enemy* enemy);

    void update(Enemy** listEnemies, int numberOfEnemies);
    void draw();
};


#endif //MONPROJETSDL_BULLETMANAGER_H

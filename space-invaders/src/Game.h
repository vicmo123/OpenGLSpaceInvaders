//
// Created by jlidou on 22/12/22.
//

#ifndef MONPROJETSDL_GAME_H
#define MONPROJETSDL_GAME_H
#include "gameDefine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "math.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "SoundManager.h"
#include "Background.h"
#include "TextPrinter.h"
#include "ScoreManager.h"

class Game {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    hmg::bounds2D bounds;
    SDL_Color clearColor;
    bool isRunning;

    //event prop
    SDL_Event event;
    const Uint8* keyBordSate;
    int xMouse,yMouse;

    //GameObjects
    TextPrinter* textPrinter;
public:
    //Managers
    PlayerManager* playerManager;
    EnemyManager* enemyManager;
    BulletManager* bulletManager;
    SoundManager* soundManager;
    Background* background;
    ScoreManager* scoreManager;

    Game();
    void init();
    void start();
    void clear();
private:
    //methode into loopgame
    void cleanWindows();
    void updateEvent();
    void update();
    void draw();
    void updateWindow();
};
#endif //MONPROJETSDL_GAME_H

//
// Created by jlidou on 22/12/22.
//

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "Game.h"

Game::Game() {
    bounds.width = WIDTH;
    bounds.height = HEIGHT;
    isRunning = true;
    clearColor = {0,0,0,255};
}
void Game::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
    SDL_CreateWindowAndRenderer(bounds.width, bounds.height, SDL_RENDERER_PRESENTVSYNC, &window, &renderer);

    //place to init all gameObject
    this->background->getInstance().init(renderer, 800, 600);
    this->bulletManager->getInstance().init(renderer);
    this->playerManager->getInstance().init(renderer, hmg::Vector2D {(bounds.width / 2) - (100.0f / 2), bounds.height * 0.8f}, 65.0f, 65.0f, PLAYER_SPRITE);
    this->enemyManager->getInstance().init(renderer);
    this->soundManager->getInstance().init();

    this->textPrinter = new TextPrinter(renderer);
}

void Game::clear() {
    //place to delete all gameObject
    textPrinter->quit();
    delete textPrinter;
    delete enemyManager;
    delete bulletManager;
    delete playerManager;
    delete background;

    //delete sdl struct
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::start() {
    while (isRunning){
        update();
        cleanWindows();
        draw();
        updateWindow();
    }
}

//<editor-fold desc="clean window update event update window">
void Game::cleanWindows() {
    SDL_SetRenderDrawColor(renderer,clearColor.r,clearColor.g,clearColor.b,clearColor.a);
    SDL_RenderClear(renderer);
}
void Game::updateEvent() {
    SDL_PumpEvents();
    keyBordSate = SDL_GetKeyboardState(nullptr);
    //SDL_PollEvent(&event);
}
void Game::updateWindow() {
    SDL_RenderPresent(renderer);
}
//</editor-fold>
//game operation
void Game::update() {
    //update modele from event
    updateEvent();

    if(keyBordSate[SDL_SCANCODE_ESCAPE]){
        isRunning = false;
    }

    //update modele
    this->background->getInstance().update();
    this->playerManager->getInstance().update();
    this->enemyManager->getInstance().run();
    this->bulletManager->getInstance().update(this->enemyManager->getInstance().getEnemiesList(), this->enemyManager->getInstance().getNumEnemies());

    textPrinter->updateText(100, 30, scoreManager->getInstance().getTextValue().c_str());
}

void Game::draw() {
    this->background->getInstance().draw();
    this->bulletManager->getInstance().draw();
    this->playerManager->getInstance().draw();
    this->enemyManager->getInstance().render();

    textPrinter->draw();
}


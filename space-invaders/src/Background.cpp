//
// Created by isi on 1/16/2023.
//

#include <iostream>
#include "Background.h"

void Background::init(SDL_Renderer *renderer, int mapWidth, int mapHeight) {
    this->renderer = renderer;

    SDL_Texture* tile01 = IMG_LoadTexture(renderer, "assets/tiles/space-tile01.png");
    SDL_Texture* tile02 = IMG_LoadTexture(renderer, "assets/tiles/space-tile02.png");
    SDL_Texture* tile03 = IMG_LoadTexture(renderer, "assets/tiles/space-tile03.png");

    int wTile, hTile;
    Uint32 format;
    SDL_QueryTexture(tile01, &format, 0, &wTile, &hTile);
    SDL_Texture* temp = SDL_CreateTexture(renderer, format, SDL_TEXTUREACCESS_TARGET,mapWidth, mapHeight);
    imagePosition = {0, 0, 80, 80};
    SDL_SetTextureBlendMode(temp,SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(renderer, temp);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 8; ++j) {
            int tileType = hmg::randomNumber::generateNumber(0, 3);

            std::cout << tileType << std::endl;

            if(tileType == 0){
                SDL_RenderCopy(renderer,tile01, 0, &imagePosition);
            } else if (tileType == 1) {
                SDL_RenderCopy(renderer,tile02, 0, &imagePosition);
            } else if (tileType == 2) {
                SDL_RenderCopy(renderer,tile03, 0, &imagePosition);
            } else {
                SDL_RenderCopy(renderer,tile01, 0, &imagePosition);
            }
            imagePosition.x = i * imagePosition.w;
            imagePosition.y = j * imagePosition.h ;

        }
    }
    imagePosition.y = 0;
    imagePosition.x = 0;
    imagePosition.w = mapWidth;
    imagePosition.h = mapHeight;

    backGround = SDL_CreateTexture(renderer, format, SDL_TEXTUREACCESS_TARGET,mapWidth, mapHeight * 3.0);
    SDL_SetTextureBlendMode(backGround,SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(renderer, backGround);
    SDL_RenderCopy(renderer,temp, 0, &imagePosition);
    imagePosition.y += mapHeight;
    SDL_RenderCopyEx(renderer,temp, 0, &imagePosition, 0, 0 , SDL_FLIP_HORIZONTAL);
    imagePosition.y += mapHeight;
    SDL_RenderCopy(renderer,temp, 0, &imagePosition);

    SDL_SetRenderTarget(renderer, 0);

    imagePosition.y = 0;
    velocity = 1.0;
    speed = 2.0f;
    lastShoot = SDL_GetTicks();
}

void Background::update() {
    if (SDL_GetTicks() - lastShoot >= deltaTime) {
        imagePosition.y = imagePosition.y - ((velocity * speed));
        if(imagePosition.y <= 0){
            imagePosition.y = imagePosition.h * 2;
        }
        lastShoot = SDL_GetTicks();
    }
}

void Background::draw() {
    SDL_RenderCopy(renderer, backGround, &imagePosition, 0);
}


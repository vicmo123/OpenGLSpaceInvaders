//
// Created by isi on 1/13/2023.
//

#ifndef MONPROJETSDL_TEXTPRINTER_H
#define MONPROJETSDL_TEXTPRINTER_H

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "gameDefine.h"

class TextPrinter {
private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Surface* temps;
    SDL_Texture* textToDraw;
    SDL_FRect textPosition;

    int fontSize;
    const char * filePath;
    SDL_Color color{255,255,255,255};

public:
    TextPrinter(SDL_Renderer* renderer);
    void updateText(int width, int height, const char * newText);
    void draw();
    void quit();
};


#endif //MONPROJETSDL_TEXTPRINTER_H

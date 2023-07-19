//
// Created by isi on 1/13/2023.
//

#include "TextPrinter.h"

TextPrinter::TextPrinter(SDL_Renderer* renderer) : renderer(renderer) {
    this->fontSize = 50;
}

void TextPrinter::updateText(int width, int height, const char * newText) {
    font = TTF_OpenFont("assets/fonts/fontarcade.ttf",this->fontSize);temps = TTF_RenderUTF8_Solid(font,newText /*timeManager->getText()*/, this->color);
    textToDraw = SDL_CreateTextureFromSurface(this->renderer,temps);
    textPosition = {0, 0, static_cast<float>(temps->w), static_cast<float>(temps->h)};

    SDL_FreeSurface(temps);
}

void TextPrinter::draw() {
    SDL_RenderCopyF(renderer, textToDraw, nullptr, &textPosition);
}

void TextPrinter::quit() {
    TTF_CloseFont(font);
    //TTF_Quit();
    //delete this;
}

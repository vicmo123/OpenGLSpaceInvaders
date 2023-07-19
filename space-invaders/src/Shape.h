//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_SHAPE_H
#define MONPROJETSDL_SHAPE_H

#include <SDL2/SDL.h>

class Shape {
private:
    SDL_Rect* shapeInt= nullptr;
    SDL_FRect* shapeFloat = nullptr;

public:
    Shape(int x, int y, int w, int h);
    Shape(float x, float y, float w, float h);
    void setPositionInt(int x, int y);
    void setPositionFloat(float x, float y);

    //Getters
    SDL_Rect *getShapeInt() const;
    SDL_FRect *getShapeFloat() const;

    //Setters
    void setShapeInt(SDL_Rect *shapeInt);
    void setShapeFloat(SDL_FRect *shapeFloat);
};


#endif //MONPROJETSDL_SHAPE_H

//
// Created by isi on 1/10/2023.
//

#include "Shape.h"

Shape::Shape(int x, int y, int w, int h) {
    this->shapeInt = new SDL_Rect{x, y, w, h};
}

Shape::Shape(float x, float y, float w, float h) {
    this->shapeFloat = new SDL_FRect{x, y, w, h};
}

void Shape::setPositionInt(int x, int y) {
    if(this->shapeInt != nullptr){
        this->shapeInt->x = x;
        this->shapeInt->y = y;
    }
}

void Shape::setPositionFloat(float x, float y) {
    if(this->shapeFloat != nullptr){
        this->shapeFloat->x = x;
        this->shapeFloat->y = y;
    }
}

SDL_Rect *Shape::getShapeInt() const {
    return shapeInt;
}

SDL_FRect *Shape::getShapeFloat() const {
    return shapeFloat;
}

void Shape::setShapeInt(SDL_Rect *shapeInt) {
    Shape::shapeInt = shapeInt;
}

void Shape::setShapeFloat(SDL_FRect *shapeFloat) {
    Shape::shapeFloat = shapeFloat;
}

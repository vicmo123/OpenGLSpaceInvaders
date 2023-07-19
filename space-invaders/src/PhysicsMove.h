//
// Created by isi on 1/15/2023.
//

#ifndef SPACE_INVADERS_PHYSICSMOVE_H
#define SPACE_INVADERS_PHYSICSMOVE_H

#include "Input.h"
#include "math.h"
#include "Shape.h"

class PhysicsMove {
private:
    Input* input;
    hmg::bounds2D objectBounds;
    Shape* objectShapeComponent;
    bool isWrapAround;

    KeyType keyType;
    Direction* possibleMovementDirections;

    float velocity;
    float speed;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
public:
    PhysicsMove(float speed, hmg::bounds2D objectBounds, Shape* objectShapeComponent, KeyType keyType, Direction* possibleMovementDirections, bool isWrapAround);
    void wrapAroundSide();
    void updateVelocity();
    void moveObject(float x, float y);
    void update();

    void setVelocity(float velocity);
    void setSpeed(float speed);
    void setDeltaTime();
};


#endif //SPACE_INVADERS_PHYSICSMOVE_H

//
// Created by isi on 1/15/2023.
//

#include "PhysicsMove.h"

PhysicsMove::PhysicsMove(float speed, hmg::bounds2D objectBounds, Shape* objectShapeComponent, KeyType keyType, Direction* possibleMovementDirections, bool isWrapAround) {
    this->velocity = 0.0f;
    this->speed = speed;
    this->isWrapAround = isWrapAround;

    this->objectBounds = objectBounds;
    this->objectShapeComponent = objectShapeComponent;

    this->keyType = keyType;
    this->possibleMovementDirections = possibleMovementDirections;
}

void PhysicsMove::wrapAroundSide() {
    if (objectShapeComponent->getShapeFloat()->x < -objectShapeComponent->getShapeFloat()->w) {
        objectShapeComponent->getShapeFloat()->x = objectBounds.width + objectShapeComponent->getShapeFloat()->w;
    }
    if (objectShapeComponent->getShapeFloat()->y < -objectShapeComponent->getShapeFloat()->h) {
        objectShapeComponent->getShapeFloat()->y = objectBounds.height + objectShapeComponent->getShapeFloat()->h;
    }
    if (objectShapeComponent->getShapeFloat()->x > objectBounds.width + objectShapeComponent->getShapeFloat()->w) {
        objectShapeComponent->getShapeFloat()->x = -objectShapeComponent->getShapeFloat()->w;
    }
    if (objectShapeComponent->getShapeFloat()->y > objectBounds.height + objectShapeComponent->getShapeFloat()->h) {
        objectShapeComponent->getShapeFloat()->y = -objectShapeComponent->getShapeFloat()->h;
    }
}


void PhysicsMove::updateVelocity() {
    Direction direction;
    direction = this->input->getInstance().manageKeyboardEventsDirections(this->keyType, this->possibleMovementDirections);

    setDeltaTime();

    if(direction == Direction::RIGHT && (this->objectShapeComponent->getShapeFloat()->x < objectBounds.width - this->objectShapeComponent->getShapeFloat()->w || isWrapAround)){
        this->velocity = 1.0f * this->speed;
        moveObject(objectShapeComponent->getShapeFloat()->x + this->velocity * deltaTime, objectShapeComponent->getShapeFloat()->y);
    }
    else if (direction == Direction::LEFT && (this->objectShapeComponent->getShapeFloat()->x > 0.0f || isWrapAround)){
        this->velocity = -1.0f * this->speed;
        moveObject(objectShapeComponent->getShapeFloat()->x + this->velocity * deltaTime, objectShapeComponent->getShapeFloat()->y);
    }
    else if (direction == Direction::UP && (this->objectShapeComponent->getShapeFloat()->y > 0.0f || isWrapAround)){
        this->velocity = -1.0f * this->speed;
        moveObject(objectShapeComponent->getShapeFloat()->x, objectShapeComponent->getShapeFloat()->y + this->velocity * deltaTime);
    }
    else if (direction == Direction::DOWN && (this->objectShapeComponent->getShapeFloat()->y < objectBounds.height - this->objectShapeComponent->getShapeFloat()->h || isWrapAround)){this->velocity = 1.0f * this->speed;
        moveObject(objectShapeComponent->getShapeFloat()->x, objectShapeComponent->getShapeFloat()->y + this->velocity * deltaTime);
    }
    else{
           this->velocity = 0.0f;
    }
}


void PhysicsMove::moveObject(float x, float y) {
    objectShapeComponent->setPositionFloat(x, y);
    this->velocity = 0.0f;

    if(isWrapAround == true){
        this->wrapAroundSide();
    }
}

void PhysicsMove::update() {
    this->updateVelocity();
}

void PhysicsMove::setVelocity(float velocity) {
    PhysicsMove::velocity = velocity;
}

void PhysicsMove::setSpeed(float speed) {
    PhysicsMove::speed = speed;
}

void PhysicsMove::setDeltaTime() {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );
}

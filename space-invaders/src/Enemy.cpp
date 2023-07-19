//
// Created by isi on 1/10/2023.
//

#include "Enemy.h"
#include "gameDefine.h"

Enemy::Enemy(SDL_Renderer *renderer, const char *spriteFilePath, hmg::Vector2D *startingScreenPosition, float width,float height, double angle) : GameObject(renderer,spriteFilePath,startingScreenPosition,width, height),angle(angle), radius(getShape()->getShapeFloat()->w / 2), maxSpeed(0.25f), maxForce(0.03)
{
    acceleration = hmg::Vector2D(0.0f, 0.0f);
    velocity = hmg::Vector2D(cos(angle), -sin(angle));
    position = hmg::Vector2D(startingScreenPosition->x, startingScreenPosition->y);
}

void Enemy::update() {
    setDeltaTime();

    acceleration.Mult(deltaTime);
    velocity.Add(&acceleration);
    velocity.Limit(maxSpeed );
    position.Add(&velocity);


    //update angle based on new velocity vector
    angle = velocity.Heading();

    updatePos();

    acceleration = hmg::Vector2D::zero();
}

void Enemy::updatePos() {
    this->getShape()->getShapeFloat()->x = position.x;
    this->getShape()->getShapeFloat()->y = position.y;
}

void Enemy::draw(){
    SDL_RenderCopyExF(this->getRenderer(), this->getSprite()->getSprite(), nullptr, this->getShape()->getShapeFloat(), angle, 0, SDL_FLIP_NONE);
}

void Enemy::wrapAround() {
    if (position.x < -this->getShape()->getShapeFloat()->w) {
        position.x = WIDTH + this->getShape()->getShapeFloat()->w;
    }

    if (position.y < -this->getShape()->getShapeFloat()->h) {
        position.y = HEIGHT + this->getShape()->getShapeFloat()->h;
    }

    if (position.x > WIDTH + this->getShape()->getShapeFloat()->w) {
        position.x = -this->getShape()->getShapeFloat()->w;
    }

    if (position.y > HEIGHT + this->getShape()->getShapeFloat()->h) {
        position.y = -this->getShape()->getShapeFloat()->h;
    }
}


hmg::Vector2D Enemy::seek(hmg::Vector2D &target) {
    hmg::Vector2D desired = hmg::Vector2D::Sub(target, position);
    desired.Normalize();
    desired.Mult(maxSpeed);
    hmg::Vector2D steer = hmg::Vector2D::Sub(desired, velocity);
    steer.Limit(maxForce);
    return steer;
}

void Enemy::run(Enemy** listEnemies, int numberOfEnemies) {
    flockTogether(listEnemies, numberOfEnemies);
    update();
    wrapAround();
}

void Enemy::applyForce(hmg::Vector2D force) {
    acceleration.Add(&force);
}

void Enemy::flockTogether(Enemy** listEnemies, int numberOfEnemies) {
    hmg::Vector2D sep = hmg::Vector2D();
    hmg::Vector2D ali = hmg::Vector2D();
    hmg::Vector2D coh = hmg::Vector2D();

    //separation
    double desiredSeparation = 50;
    int count1 = 0;

    //align
    double neighborDist = 30;
    hmg::Vector2D sum = hmg::Vector2D();
    hmg::Vector2D sum2 = hmg::Vector2D();
    int count2 = 0;

    //cohesion
    int count3 = 0;

    for (int i = 0; i < numberOfEnemies; i++) {
        double d = hmg::Vector2D::Distance(position, listEnemies[i]->position);
        if (d > 0 && d < desiredSeparation) {
            hmg::Vector2D diff = hmg::Vector2D::Sub(position, listEnemies[i]->position);
            diff.Normalize();
            diff.Div(d);
            sep.Add(&diff);
            count1++;
        }

        if (d > 0 && d < neighborDist) {
            sum.Add(&listEnemies[i]->velocity);
            count2++;

            sum2.Add(&listEnemies[i]->position);
            count3++;
        }
    }

    //separation
    if (count1 > 0) {
        sep.Div(count1);
    }

    if (sep.GetMagnitude() > 0) {
        sep.Normalize();
        sep.Mult(maxSpeed);
        sep.Sub(velocity);
        sep.Limit(maxForce);
    }

    //alignment
    if (count2 > 0) {
        sum.Div(count2);
        sum.Normalize();
        sum.Mult(maxSpeed);
        ali = hmg::Vector2D::Sub(sum, velocity);
        ali.Limit(maxForce);
    }
    else {
        ali = hmg::Vector2D();
    }

    //cohesion
    if (count3 > 0) {
        sum2.Div(count3);
        coh = seek(sum2);
    }
    else {
        coh = hmg::Vector2D();
    }

    sep.Mult(1.5f);
    ali.Mult(1.0f);
    coh.Mult(1.0f);

    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

void Enemy::setDeltaTime() {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );
}

float Enemy::getRadius() {
    return this->radius;
}

void Enemy::setIsActive(bool b) {
    this->isActive = b;
}

bool Enemy::getIsActive() {
    return isActive;
}

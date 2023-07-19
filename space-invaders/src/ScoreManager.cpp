//
// Created by isi on 1/17/2023.
//


#include "ScoreManager.h"

int ScoreManager::getScore() {
    return this->score;
}

void ScoreManager::addPoints(int pointsToAdd) {
    this->score += pointsToAdd;
}

std::string ScoreManager::getTextValue() {
    return "SCORE : " + std::to_string(this->score);
}

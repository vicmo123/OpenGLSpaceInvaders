//
// Created by isi on 1/17/2023.
//

#ifndef SPACE_INVADERS_SCOREMANAGER_H
#define SPACE_INVADERS_SCOREMANAGER_H

#include <string>
#include "Singleton.h"

class ScoreManager : public Singleton<ScoreManager>{
private:
    int score = 0;
public:
    int getScore();
    void addPoints(int pointsToAdd);
    std::string getTextValue();
};


#endif //SPACE_INVADERS_SCOREMANAGER_H

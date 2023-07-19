//
// Created by isi on 1/12/2023.
//

#ifndef SPACE_INVADERS_INPUT_H
#define SPACE_INVADERS_INPUT_H

#include <SDL2/SDL.h>
#include "Direction.h"
#include <iostream>
#include "Singleton.h"

enum KeyType{
    AWSD,
    ARROWS
};

class Input : public Singleton<Input>{
public:
    void init();
    Direction manageKeyboardEventsDirections(KeyType keyType, Direction* possibleMovementDirections);
    bool checkSpaceBar();
};


#endif //SPACE_INVADERS_INPUT_H

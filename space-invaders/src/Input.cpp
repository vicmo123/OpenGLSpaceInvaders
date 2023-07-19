//
// Created by isi on 1/12/2023.
//

#include "Input.h"

void Input::init() {

}

/**
 * Function for managing keyboard keys for directions.
 * @param KeyType : AWSD or ARROW keys using enum.
 * @param Direction : use direction array to choose possible moving directions.
 * @return will return the desired direction according to the keyboard events.
 */
Direction Input::manageKeyboardEventsDirections(KeyType keyType, Direction* possibleMovementDirections) {
    auto keyBordSate = SDL_GetKeyboardState(nullptr);

    bool right = false; bool left = false; bool up = false; bool down = false;

    for (int i = 0; i < 4; ++i) {
        switch (possibleMovementDirections[i]) {
            case Direction::RIGHT:
                right = true;
                break;
            case Direction::LEFT:
                left = true;
                break;
            case Direction::UP:
                up = true;
                break;
            case Direction::DOWN:
                down = true;
                break;
        }
    }

    switch (keyType) {
        case KeyType::AWSD:
            if (keyBordSate[SDL_SCANCODE_D] && right) {
                return Direction::RIGHT;
            }
            else if (keyBordSate[SDL_SCANCODE_A] && left){
                return Direction::LEFT;
            }
            else if (keyBordSate[SDL_SCANCODE_W] && up){
                return Direction::UP;
            }
            else if (keyBordSate[SDL_SCANCODE_S] && down){
                return Direction::DOWN;
            }
            else{
                return Direction::NO_DIRECTION;
            }
            break;
        case KeyType::ARROWS:
            if (keyBordSate[SDL_SCANCODE_RIGHT] && right) {
                return Direction::RIGHT;
            }
            else if (keyBordSate[SDL_SCANCODE_LEFT] && left){
                return Direction::LEFT;
            }
            else if (keyBordSate[SDL_SCANCODE_UP] && up){
                return Direction::UP;
            }
            else if (keyBordSate[SDL_SCANCODE_DOWN] && down){
                return Direction::DOWN;
            }
            else {
                return Direction::NO_DIRECTION;
            }
            break;
        default:
            std::cout << "unhandeled switch in input : " << keyType << std::endl;
            break;
    }
}

bool Input::checkSpaceBar() {
    auto keyBordSate = SDL_GetKeyboardState(nullptr);

    if (keyBordSate[SDL_SCANCODE_SPACE]){
        return true;
    }
    else {
        return false;
    }
}


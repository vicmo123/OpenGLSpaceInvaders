//
// Created by isi on 1/10/2023.
//

#ifndef MONPROJETSDL_PLAYERMANAGER_H
#define MONPROJETSDL_PLAYERMANAGER_H

#include "Singleton.h"
#include "Player.h"
#include "math.h"

class PlayerManager : public Singleton<PlayerManager> {
private:
    hmg::Vector2D* playerSize = nullptr;
    hmg::Vector2D* initialPosition = nullptr;
    Player* player = nullptr;
public:
    void init(SDL_Renderer *renderer, hmg::Vector2D startingScreenPosition,float width, float height, const char *spriteFilePath);

    const hmg::Vector2D &getPlayerSize() const;
    void setPlayerSize(hmg::Vector2D *playerSize);
    const hmg::Vector2D &getInitialPosition() const;
    void setInitialPosition(hmg::Vector2D *initialPosition);
    Player *getPlayer() const;
    void draw();
    void update();
    void setPlayer(Player *player);
};


#endif //MONPROJETSDL_PLAYERMANAGER_H

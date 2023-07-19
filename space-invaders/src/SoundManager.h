//
// Created by isi on 1/16/2023.
//

#ifndef SPACE_INVADERS_SOUNDMANAGER_H
#define SPACE_INVADERS_SOUNDMANAGER_H

#include <string>
#include <map>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include "Singleton.h"

class SoundManager : public Singleton<SoundManager>{
private :
    std::vector<Mix_Chunk *> wavSounds;
    std::vector<Mix_Music *> mp3Sounds;
    Mix_Music *currentMp3;

public :
    SoundManager();
    void init();

    void playWav(int channel, int index, int nbLoops);
    void playMp3(int index, int nbLoops);

    virtual ~SoundManager();
};


#endif //SPACE_INVADERS_SOUNDMANAGER_H

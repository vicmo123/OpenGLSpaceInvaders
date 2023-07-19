//
// Created by isi on 1/16/2023.
//

#include "SoundManager.h"
#include <SDL2/SDL_mixer.h>

SoundManager::SoundManager() {
}

void SoundManager::init() {
    //WAV
    Mix_Chunk *laser1 = Mix_LoadWAV("assets/sounds/shootingSound.wav");
    Mix_Chunk *laser2 = Mix_LoadWAV("assets/sounds/explosion.wav");

    this->wavSounds.push_back(laser1);
    this->wavSounds.push_back(laser2);

//    //MP3
//    this->currentMp3 = Mix_LoadMUS("assets/Sounds/test.mp3");
//    this->mp3Sounds.push_back(this->currentMp3);
}

void SoundManager::playWav(int channel, int index, int nbLoops) {
    Mix_PlayChannel(channel, wavSounds[index], nbLoops);
}

void SoundManager::playMp3(int index, int nbLoops) {
    Mix_PlayMusic(mp3Sounds[index], nbLoops);
}

SoundManager::~SoundManager() {
    if (wavSounds.size() >= 1) {
        for (int i = 0; i < wavSounds.size(); i++) {
            Mix_FreeChunk(wavSounds[i]);
        }
    }

    if (mp3Sounds.size() >= 1) {
        for (int i = 0; i < mp3Sounds.size(); i++) {
            Mix_FreeMusic(mp3Sounds[i]);
        }
    }
}
#include "../include/Music.h"

Music::Music(){
    music = nullptr;
}

Music::Music(std::string file){
    music = nullptr;
    Open(file);
}
Music::~Music(){
    if(music){
        Stop(0);
    }
    Resources::ClearMusics();
}

void Music::Play(int times){
    if (music != nullptr) {
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop){
    if(music != nullptr){
        Mix_FadeOutMusic(msToStop);
    }
}

void Music::Open(std::string file){
    music = Resources::GetMusic(file);
    if (music == nullptr) {
        std::cout << "Problemas na hora de abrir a musica" << std::endl;
    }
}

bool Music::isOpen(){
    if(music == nullptr){
        return false;
    }
    return true;
}

#include "../include/Sound.h"

Sound::Sound(GameObject& associated) : Component (associated){
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, const char* file) : Component(associated){
    chunk = nullptr;
    Open(file);
}

Sound::~Sound(){
    if (chunk){
        Stop();
    }
    Resources::ClearSounds();
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, (times-1));
}

void Sound::Stop(){
    if (chunk){
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(const char* file){
    chunk = Resources::GetSound(file);
    if(!chunk){
        std::cout << "Problemas para abrir o som." << '\n';
    }
}

bool Sound::IsOpen(){
    if (chunk){
        return true;
    }
    return false;
}

void Sound::Update(float dt){}

void Sound::Render(){}

bool Sound::Is(std::string type){
    return type == "Sound";
}

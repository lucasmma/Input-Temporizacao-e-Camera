#include "Resources.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;


SDL_Texture* Resources::GetImage(std::string file){
    std::unordered_map<std::string, SDL_Texture*>::iterator it;
    it = imageTable.find(file);
    if(it != imageTable.end()){
        return imageTable.at(file);
    }
    else{
        SDL_Texture *textura = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
        imageTable.insert({file,textura});
        return imageTable.at(file);
    }
}
void Resources::ClearImage(){
    for ( auto it = imageTable.begin(); it != imageTable.end(); ++it ){
        SDL_DestroyTexture(it->second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
    std::unordered_map<std::string, Mix_Music*>::iterator it;
    it = musicTable.find(file);
    if(it != musicTable.end()){
        return musicTable.at(file);
    }
    else{
        Mix_Music *musica = Mix_LoadMUS(file.c_str());
        musicTable.insert({file, musica});
        return musicTable.at(file);
    }
}
void Resources::ClearMusics(){
    for ( auto it = musicTable.begin(); it != musicTable.end(); ++it ){
        Mix_FreeMusic(it->second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file){
    std::unordered_map<std::string, Mix_Chunk*>::iterator it;
    it = soundTable.find(file);
    if(it != soundTable.end()){
        return soundTable.at(file);
    }
    else{
        Mix_Chunk *som = Mix_LoadWAV(file.c_str());
        soundTable.insert({file, som});
        return soundTable.at(file);
    }

}
void Resources::ClearSounds(){
    for ( auto it = soundTable.begin(); it != soundTable.end(); ++it ){
        Mix_FreeChunk(it->second);
    }
    soundTable.clear();
}

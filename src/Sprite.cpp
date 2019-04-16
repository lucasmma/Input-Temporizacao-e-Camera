#include "../include/Sprite.h"

Sprite::Sprite(GameObject& associated) : Component(associated){
    texture = nullptr;
}

Sprite::Sprite(GameObject& associated,std::string file) : Component(associated){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    Resources::ClearImage();
}

void Sprite::Open(std::string file){
    texture = Resources::GetImage(file);
    if(texture == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    clipRect.x = 0;
    clipRect.y = 0;
    clipRect.w = width;
    clipRect.h = height;
    associated.box.h = height;
    associated.box.w = width;
    return;
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
    return;
}

void Sprite::Render(){
    SDL_Rect rect;
    Render(associated.box.x - Camera::pos.x, associated.box.y - Camera::pos.y);
}
void Sprite::Render(float x, float y){
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = clipRect.w;
    rect.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &rect);
}



int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    if(texture == nullptr){
        return false;
    }
    else{
        return true;
    }
}

bool Sprite::Is(std::string type){//verificar o retorno
    return type == "Sprite";
}

void Sprite::Update(float dt){

}

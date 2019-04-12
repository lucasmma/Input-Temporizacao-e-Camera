#include "../include/Face.h"

Face::Face(GameObject& associated) : Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints-=damage;
    if(hitpoints<=0){
        associated.RequestDelete();
        if (associated.GetComponent("Sound")){
            Sound *sound = dynamic_cast<Sound*>(associated.GetComponent("Sound"));
            sound->Play();
        }
    }
}

void Face::Update(float dt){}

void Face::Render(){}

bool Face::Is(std::string type){
    return type == "Face";
}

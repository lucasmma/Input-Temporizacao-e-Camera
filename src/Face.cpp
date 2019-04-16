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

void Face::Update(float dt){
    Face *face = dynamic_cast<Face*>(associated.GetComponent("Face"));
    if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
		if(associated.box.Contains(InputManager::GetInstance().GetMouseX(), InputManager::GetInstance().GetMouseY()) ) {
			if ( nullptr != face) {
				// Aplica dano
				face->Damage(std::rand() % 10 + 10);
				// Sai do loop (só queremos acertar um)
			}
		}
    }
}

void Face::Render(){}

bool Face::Is(std::string type){
    return type == "Face";
}

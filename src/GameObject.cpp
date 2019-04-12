#include "../include/GameObject.h"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for (int i = (components.size()-1); i >= 0; i--) {
        components.erase(components.begin()+i);
    }
    components.clear();
}

void GameObject::Update(float dt){
    for (unsigned int i = 0; i < components.size(); i++) {
        components[i].get()->Update(dt);
    }
}

void GameObject::Render(){
    for (unsigned int i = 0; i < components.size(); i++) {
        components[i].get()->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component *cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt){
    for (unsigned int i = 0; i < components.size(); i++) {
        if (components[i].get() == cpt){
            components.erase(components.begin()+i);
        }
    }
}

Component *GameObject::GetComponent(std::string type){
    for (unsigned int i = 0; i < components.size(); i++) {
        if (components[i].get()->Is(type)){
            return components[i].get();
        }
    }
    return nullptr;
}

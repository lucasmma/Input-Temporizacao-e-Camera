#include "../include/Camera.h"
#include "../include/InputManager.h"

Vec2 Camera::pos;
Vec2 Camera::speed;
Vec2 Camera::speed.x = 100;
Vec2 Camera::speed.y = 100;
GameObject* Camera::focus;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    if(focus){
        pos.x = focus->box.x - 512;
        pos.y = focus->box.y - 300;
    }
    else{
        if(InputManager::GetInstance().KeyPress(LEFT_ARROW_KEY)){
            pos.x -= speed.x * dt;
        }
        if(InputManager::GetInstance().KeyPress(RIGHT_ARROW_KEY)){
            pos.x += speed.x * dt;
        }
        if(InputManager::GetInstance().KeyPress(DOWN_ARROW_KEY)){
            pos.y -= speed.y * dt;
        }
        if(InputManager::GetInstance().KeyPress(UP_ARROW_KEY)){
            pos.x += speed.x * dt;
        }
    }
}

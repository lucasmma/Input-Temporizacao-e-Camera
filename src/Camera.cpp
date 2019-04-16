#include "../include/Camera.h"
#include "../include/InputManager.h"
#include "../include/Vec2.h"

GameObject* Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    Camera::speed.x = 300.0;
    Camera::speed.y = 300.0;
    if(focus){
        pos.x = focus->box.x - 512.0;
        pos.y = focus->box.y - 300.0;
    }
    else{
        if(InputManager::GetInstance().KeyIsDown(LEFT_ARROW_KEY)){
            pos.x -= speed.x * dt;
        }
        if(InputManager::GetInstance().KeyIsDown(RIGHT_ARROW_KEY)){
            pos.x += speed.x * dt;
        }
        if(InputManager::GetInstance().KeyIsDown(UP_ARROW_KEY)){
            pos.y -= speed.y * dt;
        }
        if(InputManager::GetInstance().KeyIsDown(DOWN_ARROW_KEY)){
            pos.y += speed.y * dt;
        }
    }
}

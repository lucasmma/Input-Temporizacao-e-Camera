#include "../include/InputManager.h"


InputManager::InputManager(){
    for (int i = 0; i < 6; i++) {
        MouseState[i] = false;
        MouseUpdate[i] = 0;
    }
    quitRequested = false;
    updateCounter = 0;
}

InputManager::~InputManager(){

}

void InputManager::Update(){
    updateCounter++;
    SDL_GetMouseState(&MouseX, &MouseY);
    quitRequested = false;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT){
            quitRequested = true;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            MouseState[event.button.button] = true;
            MouseUpdate[event.button.button] = updateCounter;
        }
        if (event.type == SDL_MOUSEBUTTONUP) {
            MouseState[event.button.button] = false;
            MouseUpdate[event.button.button] = updateCounter;
        }
        if(event.type == SDL_KEYDOWN){
            if(event.key.repeat != 1){
                KeyState[event.key.keysym.sym] = true;
                KeyUpdate[event.key.keysym.sym] = updateCounter;
            }
        }
        if(event.type == SDL_KEYUP){
            KeyState[event.key.keysym.sym] = false;
            KeyUpdate[event.key.keysym.sym] = updateCounter;
        }
    }
}

bool InputManager::KeyPress(int key){
    if(KeyState[key] && KeyUpdate[key] == updateCounter){
        return true;
    }
    else{
        return false;
    }
}

bool InputManager::KeyRelease(int key){
    if(!KeyState[key] && KeyUpdate[key] == updateCounter){
        return true;
    }
    else{
        return false;
    }
}

bool InputManager::KeyIsDown(int key){
    if(KeyState[key]){
        return true;
    }
    else{
        return false;
    }
}

bool InputManager::MousePress(int button){
    if(MouseState[button]  && MouseUpdate[button] == updateCounter){
        return true;
    }
    else{
        return false;
    }
}

bool InputManager::MouseRelease(int button){
    if(!MouseState[button] && MouseUpdate[button] == updateCounter){
        return true;
    }
    else{
        return false;
    }
}

bool InputManager::MouseIsDown(int button){
    if(MouseState[button]){
        return true;
    }
    else{
        return false;
    }
}
int InputManager::GetMouseX(){
    return MouseX;
}

int InputManager::GetMouseY(){
    return MouseY;
}

bool InputManager::QuitRequested(){
    return quitRequested;
}

InputManager& InputManager::GetInstance(){
    static InputManager *instance = new InputManager();
    return *instance;
}

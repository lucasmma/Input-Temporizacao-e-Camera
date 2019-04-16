#ifndef GAME_H
    #include "Game.h"
#endif

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager {
public:
    void Update();

    bool KeyPress(int key);
    bool KeyRelease(int key);
    bool KeyIsDown(int key);

    bool MousePress(int button);
    bool MouseRelease(int button);
    bool MouseIsDown(int button);

    int GetMouseX();
    int GetMouseY();

    bool QuitRequested();

    static InputManager& GetInstance();


private:
    static InputManager instance;

    InputManager();
    ~InputManager();

    bool MouseState[6];
    int MouseUpdate[6];


    std::unordered_map<int, bool> KeyState;
    std::unordered_map<int, int> KeyUpdate;

    bool quitRequested;

    int updateCounter;

    int MouseX;
    int MouseY;

};

#endif

#ifndef GAME_H
    #include "Game.h"
#endif


#ifndef STATE_H
#define STATE_H

#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"
#include "Sound.h"
#include "Face.h"
#include "Vec2.h"
#include "TileMap.h"
#include "InputManager.h"
#include "Camera.h"

class State{
public:
    State();
    ~State();
    bool QuitRequest();
    void LoadAssets();
    void Update(float dt);
    void Render();


private:
    Sprite* bg;
    Music* music;
    bool quitRequest;
    void AddObject(int mouseX, int mouseY);
    std::vector<std::unique_ptr<GameObject>> objectArray;
};



#endif

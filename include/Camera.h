#ifndef GAME_H
    #include "Game.h"
#endif

#ifndef CAMERA_H
#define CAMERA_H
#include "GameObject.h"
#include "Vec2.h"


class Camera{
public:
    static void Follow(GameObject *newFocus);
    static void Unfollow();
    static void Update(float dt);


    static Vec2 speed;
    static Vec2 pos;

private:
    static GameObject* focus;

};
#endif

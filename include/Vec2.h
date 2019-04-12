#ifndef GAME_H
    #include "Game.h"
#endif

#ifndef VEC2_H
#define VEC2_H

class Vec2 {
public:
    Vec2(float x, float y);
    float x;
    float y;
    Vec2 GetRotated(float x);



    Vec2 operator+(Vec2 vec){
        return Vec2(x+vec.x, y+vec.y);
    }


};

#endif

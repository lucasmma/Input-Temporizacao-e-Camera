#ifndef GAME_H
#include "Game.h"
#endif
#ifndef RECT_H
#define RECT_H


class Rect{
public:
    float x;
    float y;
    float w;
    float h;
    bool Contains(float a, float b);

};

#endif

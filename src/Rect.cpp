#include "../include/Rect.h"

bool Rect::Contains(float a, float b) {
    if(((a>x) && (a<x+w)) && ((b>y) && (b<y+h))){
        return true;
    }
    return false;
}

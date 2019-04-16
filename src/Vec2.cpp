#include "../include/Vec2.h"

Vec2 Vec2::GetRotated(float pi){
    float x;
    float y;
    x = (this->x * cos(pi)) - (this->y * sin(pi));
    y = (this->y * cos(pi)) + (this->x * sin(pi));
    this->x = x;
    this->y = y;

    return *this;
}
Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}
Vec2::Vec2(){
    x = 0.0;
    y = 0.0;
}

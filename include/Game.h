#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>
#include <unordered_map>
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "../include/SDL_include.h"
#include "State.h"
#define PI 3.14159265359

class Game{
public:
    ~Game();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();
    float GetDeltaTime();


private:

    Game(std::string title, int width, int height);
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
    void CalculateDeltaTime();
    float dt;
    int frameStart;

};

#endif

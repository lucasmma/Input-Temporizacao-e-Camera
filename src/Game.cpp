#include "../include/Game.h"

Game* Game::instance;
Game::Game(std::string title, int width, int height){
    srand(time(NULL));
    if (instance != nullptr) {
        std::cout << "Problema identificado (objeto intanciado mais de uma vez)" << std::endl;
    }
    else{
        instance = this;
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
            std::cout << "Falha ao iniciar o SDL" << std::endl;
            return;
        }
        if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0){
            std::cout << "Falha ao inicializar o SDL_Img" << std::endl;
        }
        //implementar o if para deteccao de erros
        Mix_Init(MIX_INIT_OGG);
        if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
            std::cout << "Erro no OpenAudio" << std::endl;
        }
        Mix_AllocateChannels(32);
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    state = new State();
    dt = 0;
    frameStart = 0;
}

Game::~Game(){
    delete state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

Game& Game::GetInstance(){
    if (instance != nullptr){
        // std::cout << "Intancia ja existente" << std::endl;
        return *instance;
    }
    else{
        // std::cout << "opafion" << '\n';
        Game *game = new Game("Lucas Mendonca 170149668", 1024, 600);
        instance = game;
        return *game;
    }
}

State& Game::GetState(){
        return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}


void Game::Run(){
    while(state->QuitRequest() != true){
        CalculateDeltaTime();
        InputManager::GetInstance().Update();
        state->Update(dt);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    return;
}

void Game::CalculateDeltaTime(){
    dt = SDL_GetTicks() - frameStart;
    frameStart = SDL_GetTicks();
    dt = dt / 1000;
}

float Game::GetDeltaTime(){
    return dt;
}

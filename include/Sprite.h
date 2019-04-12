#ifndef GAME_H
    #include "Game.h"
#endif


#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "Resources.h"
#include "GameObject.h"

class Sprite :  public Component {
public:
    Sprite(GameObject& associated);
    Sprite(GameObject& associated, std::string file);
    ~Sprite();
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render();
    void Render(float x, float y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    bool Is(std::string type);
    void Update(float dt);

private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
};

#endif

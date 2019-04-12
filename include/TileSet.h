#ifndef GAME_H
    #include "Game.h"
#endif

#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"


class TileSet {
public:
    TileSet(int tileWidth, int tileHeight, std::string file);
    ~TileSet();
    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();

private:
    Sprite *tileSet;

    int rows;
    int columns;

    int tileWidth;
    int tileHeight;

};

#endif

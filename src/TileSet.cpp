#include "../include/TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file){
    GameObject *go = new GameObject();//cria um GO para abrir a imagem
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    tileSet = new Sprite(*go, file);
    rows = tileSet->GetHeight() / tileHeight;
    columns = tileSet->GetWidth() / tileWidth;
}

TileSet::~TileSet(){
    if(this->tileSet){
        delete tileSet;
    }
}

void TileSet::RenderTile(unsigned index, float x, float y){
    if(index >= 0 && index < (rows * columns)){
        int h = tileHeight;
        int w = tileWidth;
        int x1 = (index % columns) * w;
        int y1 = ((int)(index / columns)) * h;
        tileSet->SetClip(x1, y1, w, h);
        tileSet->Render(x, y);
    }

}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}

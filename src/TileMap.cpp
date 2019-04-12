#include "../include/TileMap.h"


TileMap::TileMap(GameObject &associated, std::string file, TileSet *tileSet): Component(associated){
    Load(file);
    this->tileSet = tileSet; //iguala os ponteiros;
}

TileMap::~TileMap(){
    if(tileSet){
        delete tileSet;
    }
}

void TileMap::Load(std::string file){
    std::ifstream FileReader;
    std::string num;
    std::stringstream auxiliar;
    int numero;
    int posicao=0;
    FileReader.open(file);
    if(FileReader.is_open()){
        while(!FileReader.eof()){
            auxiliar.clear();
            getline(FileReader, num, ',');
            auxiliar << num;
            auxiliar >> numero;
            // std::cout << numero << '\n';
            if(posicao == 0){
                mapWidth = numero;
            }
            else{
                if(posicao == 1){
                    mapHeight = numero;
                }
                else{
                    if(posicao == 2){
                        mapDepth = numero;
                    }
                    else{
                        tileMatrix.push_back(numero-1);
                    }
                }
            }
            posicao++;
        }
    }
    else{
      std::cout << "Problemas na abertura do arquivo tileMap.txt" << '\n';
    }
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet; //troca o tileSet
}

int& TileMap::At(int x, int y, int z){
    int indice;
    indice = (mapWidth*mapHeight*z)+(mapWidth*y)+x;
    return tileMatrix[indice];

}

void TileMap::Render(){
  int cameraX = 0;
  int cameraY = 0;
    for (int deepth = 0; deepth < GetDepth(); deepth++) {
      RenderLayer(deepth,cameraX,cameraY);
    }

}
void TileMap::Update(float dt){

}
bool TileMap::Is(std::string type){
    return type == "TileMap";
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    for (int w = 0; w < tileSet->GetTileWidth(); w++) {
      for (int h = 0; h < tileSet->GetTileHeight(); h++) {
          tileSet->RenderTile(At(w,h,layer),(w*tileSet->GetTileWidth()),(h*tileSet->GetTileHeight()));
      }
    }

}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}

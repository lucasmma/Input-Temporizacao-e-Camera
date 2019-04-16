#include "../include/State.h"

State::State(){
    quitRequest = false;
    GameObject *go = new GameObject();
    GameObject *go1 = new GameObject();
    go->box.x = 0;
    go1->box.x = 0;
    go->box.y = 0;
    go1->box.y = 0;
    TileSet *tileset = new TileSet(64, 64, "assets/img/tileset.png");
    TileMap *tilemap = new TileMap(*go1, "assets/map/tileMap.txt", tileset);
    bg = new Sprite(*go ,"assets/img/ocean.jpg");
    CameraFollower *follower = new CameraFollower(*go);
    music = new Music("assets/audio/stageState.ogg");
    go->AddComponent(bg);
    go->AddComponent(follower);
    go1->AddComponent(tilemap);
    music->Play();
    objectArray.emplace_back(go);
    objectArray.emplace_back(go1);
}

State::~State(){
    // if (music) {
    //     delete music;
    // }
    // if (bg) {
    //     delete bg;
    // }
    for (int i = objectArray.size() - 1; i >= 0; --i) {
        objectArray.erase(objectArray.begin()+i);
    }
    objectArray.clear();
    //verificar isso dps
}


bool State::QuitRequest(){
    return quitRequest;
}



void State::LoadAssets(){
    //trabalho posterior
}


void State::Update(float dt){
    Camera::Update(dt);
    if(InputManager::GetInstance().QuitRequested() || InputManager::GetInstance().KeyPress(ESCAPE_KEY)){
        quitRequest = true;
    }
    if(InputManager::GetInstance().KeyIsDown(SDLK_SPACE)){
        Vec2 objPos = Vec2(200 , 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2(InputManager::GetInstance().GetMouseX(), InputManager::GetInstance().GetMouseY());
        AddObject(objPos.x,objPos.y);
    }
    for (unsigned int i = 0; i < objectArray.size() ; i++) {
        objectArray[i].get()->Update(dt);
    }
    for (int i = objectArray.size() - 1; i >= 0; --i) {
        if(objectArray[i].get()->IsDead()){
            objectArray.erase(objectArray.begin()+i);
        }
    }
}


void State::Render(){
    for (unsigned int i = 0; i < objectArray.size(); i++) {
        Component* tilemap = objectArray[i]->GetComponent("TileMap");
        if(tilemap){
            objectArray[i]->box.x = Camera::pos.x;
            objectArray[i]->box.y = Camera::pos.y;
        }

        objectArray[i].get()->Render();
    }
}

// void State::Input() {
// 	SDL_Event event;
// 	int mouseX, mouseY;
//
// 	// Obtenha as coordenadas do mouse
// 	SDL_GetMouseState(&mouseX, &mouseY);
//
// 	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
// 	while (SDL_PollEvent(&event)) {
//
// 		// Se o evento for quit, setar a flag para terminação
// 		if(event.type == SDL_QUIT) {
// 			quitRequest = true;
// 		}
//
// 		// Se o evento for clique...
// 		if(event.type == SDL_MOUSEBUTTONDOWN) {
//
// 			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
// 			for(int i = objectArray.size() - 1; i >= 0; --i) {
// 				// Obtem o ponteiro e casta pra Face.
// 				GameObject* go = (GameObject*) objectArray[i].get();
// 				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
// 				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
// 				// ao usar get(), violamos esse princípio e estamos menos seguros.
// 				// Esse código, assim como a classe Face, é provisório. Futuramente, para
// 				// chamar funções de GameObjects, use objectArray[i]->função() direto.
//
// 				if(go->box.Contains(mouseX, mouseY) ) {
// 					Face* face = (Face*)go->GetComponent( "Face" );
// 					if ( nullptr != face ) {
// 						// Aplica dano
// 						face->Damage(std::rand() % 10 + 10);
// 						// Sai do loop (só queremos acertar um)
// 						break;
// 					}
// 				}
// 			}
// 		}
// 		if( event.type == SDL_KEYDOWN ) {
// 			// Se a tecla for ESC, setar a flag de quit
// 			if( event.key.keysym.sym == SDLK_ESCAPE ) {
// 				quitRequest = true;
// 			}
// 			// Se não, crie um objeto
// 			else {
// 				Vec2 objPos = Vec2(200 , 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
// 				AddObject(objPos.x,objPos.y);
// 			}
// 		}
// 	}
// }

void State::AddObject(int mouseX, int mouseY){
        GameObject *go = new GameObject();
        Face *fc = new Face(*go);
        Sprite *sp = new Sprite(*go, "assets/img/penguinface.png");
        go->box.x = mouseX + Camera::pos.x;
        go->box.y = mouseY + Camera::pos.y;
        go->AddComponent(fc);
        go->AddComponent(sp);
        Sound *sd = new Sound(*go, "assets/audio/boom.wav");
        go->AddComponent(sd);
        objectArray.emplace_back(go);
        std::cout << objectArray.size() << '\n';
        //verificar
}

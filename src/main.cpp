#include "../include/Game.h"

int main(int argc, char const **argv) {
    Game game = Game::GetInstance();
    game.Run();
    return 0;
}

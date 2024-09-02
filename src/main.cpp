#include "game/game.hpp"
#include <iostream>
#include <vector>
#include "entity.hpp"


// remember to add inline parameters of the subroutine main else SDL2 will not work
int main(int argc, char* argv[]) {
    Game& game = Game::get_instance();

    game.init();
    game.run();
    return 0;
}
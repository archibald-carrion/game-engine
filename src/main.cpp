#include "game/game.hpp"

// #include <SDL2/SDL.h>
// #include <glm/glm.hpp>
#include <iostream>
// #include <sol/sol.hpp>
#include <vector>
// #include "config_management.hpp"
#include "entity.hpp"






// remember to add inline parameters of the subroutine main else SDL2 will not work
int main(int argc, char* argv[]) {

    // std::cout << "A " << Entity<skull>::get_id() << std::endl;
    // std::cout << "B " << Entity<other_asset>::get_id() << std::endl;

    Game game;
    game.init();
    game.run();
    return 0;
}
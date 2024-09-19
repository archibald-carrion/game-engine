#ifndef LUA_BINDING_HPP
#define LUA_BINDING_HPP

#include <string>
#include "../game/game.hpp"

// Controls

bool is_action_activated(const std::string& action) {
    return Game::get_instance().controller_manager->is_key_pressed(action);
}




#endif // LUA_BINDING_HPP
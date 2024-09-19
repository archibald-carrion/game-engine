#ifndef LUA_BINDING_HPP
#define LUA_BINDING_HPP

#include <string>

#include"../ECS/ECS.hpp"
#include "../game/game.hpp"
#include "../components/RigidBodyComponent.hpp"

// Controls

bool is_action_activated(const std::string& action) {
    return Game::get_instance().controller_manager->is_key_pressed(action);
}

// Rigid body component

void set_velocity(Entity e, float x, float y) {
    auto& rigid_body = e.get_component<RigidBodyComponent>();
    rigid_body.velocity.x = x;
    rigid_body.velocity.y = y;
}


#endif // LUA_BINDING_HPP
#ifndef LUA_BINDING_HPP
#define LUA_BINDING_HPP

#include <string>
#include <tuple>

#include"../ECS/ECS.hpp"
#include "../game/game.hpp"
#include "../components/RigidBodyComponent.hpp"
#include "../components/box_collider_component.hpp"
#include "../components/sprite_component.hpp"
#include "../components/transform_component.hpp"
#include "../components/tag_component.hpp"

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

// Tag component
std::string get_tag(Entity entity){
    return entity.get_component<TagComponent>().tag;
}

// Transform component
std::tuple<int, int> get_position(Entity e) {
    const auto& transform = e.get_component<TransformComponent>();
    return {static_cast<int>(transform.position.x), static_cast<int>(transform.position.y)};
}

std::tuple<int, int> get_velocity(Entity e) {
    const auto& rigid_body = e.get_component<RigidBodyComponent>();
    return {static_cast<int>(rigid_body.velocity.x), static_cast<int>(rigid_body.velocity.y)};
}

void set_position(Entity e, int x, int y) {
    auto& transform = e.get_component<TransformComponent>();
    transform.position.x = static_cast<float>(x);
    transform.position.y = static_cast<float>(y);
}

std::tuple<int, int> get_size(Entity e) {
    const auto& sprite = e.get_component<SpriteComponent>();
    const auto& transform = e.get_component<TransformComponent>();
    
    int width = sprite.width * transform.scale.x;
    int height = sprite.height * transform.scale.y;

    return {width, height};
}

// Scenes
void go_to_scene(const std::string& scene_name) {
    Game::get_instance().scene_manager->set_next_scene(scene_name);
    Game::get_instance().scene_manager->stop_scene();
}

// Collisions
bool left_collision(Entity e, Entity other) {
    const auto& e_collider = e.get_component<BoxColliderComponent>();
    const auto& e_transform = e.get_component<TransformComponent>();
    const auto& other_collider = other.get_component<BoxColliderComponent>();
    const auto& other_transform = other.get_component<TransformComponent>();

    float e_x = e_transform.previous_position.x;
    float e_y = e_transform.previous_position.y;

    float e_h = static_cast<float>(e_collider.height);

    float other_x = other_transform.previous_position.x;
    float other_y = other_transform.previous_position.y;

    float other_h = static_cast<float>(other_collider.height);

    // check if left side of e is colliding with other
    return (
        other_y < e_y + e_h &&
        other_y + other_h > e_y &&
        other_x < e_x
    );
}

bool right_collision(Entity e, Entity other) {
    const auto& e_collider = e.get_component<BoxColliderComponent>();
    const auto& e_transform = e.get_component<TransformComponent>();
    const auto& other_collider = other.get_component<BoxColliderComponent>();
    const auto& other_transform = other.get_component<TransformComponent>();

    float e_x = e_transform.previous_position.x;
    float e_y = e_transform.previous_position.y;

    float e_h = static_cast<float>(e_collider.height);

    float other_x = other_transform.previous_position.x;
    float other_y = other_transform.previous_position.y;

    float other_h = static_cast<float>(other_collider.height);

    // check if left side of e is colliding with other
    return (
        other_y < e_y + e_h &&
        other_y + other_h > e_y &&
        other_x > e_x
    );
}


#endif // LUA_BINDING_HPP
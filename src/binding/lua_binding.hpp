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
#include "../components/sound_component.hpp"
#include "../components/tag_component.hpp"


// Sounds thingies functions 
void play_sound(const std::string& sound_id) {
    Game::get_instance().audio_manager->play_sound_effect(sound_id);
}

void play_music(const std::string& music_id) {
    Game::get_instance().audio_manager->play_music(music_id);
}






// void play_sound(Entity e) {
//     Game::get_instance().registry->get_system<SoundSystem>().play_sound(e);
// }

// void stop_sound(Entity e) {
//     Game::get_instance().registry->get_system<SoundSystem>().stop_sound(e);
// }

// void pause_sound(Entity e) {
//     Game::get_instance().registry->get_system<SoundSystem>().pause_sound(e);
// }

// void resume_sound(Entity e) {
//     Game::get_instance().registry->get_system<SoundSystem>().resume_sound(e);
// }

// void set_sound_volume(Entity e, int volume) {
//     auto& sound = e.get_component<SoundComponent>();
//     sound.volume = volume;
// }

// int get_sound_volume(Entity e) {
//     const auto& sound = e.get_component<SoundComponent>();
//     return sound.volume;
// }

// void set_sound_loop(Entity e, bool is_looping) {
//     auto& sound = e.get_component<SoundComponent>();
//     sound.is_looping = is_looping;
// }

// bool is_sound_looping(Entity e) {
//     const auto& sound = e.get_component<SoundComponent>();
//     return sound.is_looping;
// }

// void load_sound(Entity e, const std::string& sound_id) {
//     auto& sound = e.get_component<SoundComponent>();
//     sound.sound_id = sound_id;
//     sound.sound = Game::get_instance().assets_manager->get_sound(sound_id);
// }

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
void set_rotation(Entity e, float angle) {
    auto& transform = e.get_component<TransformComponent>();
    transform.rotation = angle;
}

float get_rotation(Entity e) {
    return e.get_component<TransformComponent>().rotation;
}

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

bool top_collision(Entity e, Entity other) {
    const auto& e_collider = e.get_component<BoxColliderComponent>();
    const auto& e_transform = e.get_component<TransformComponent>();
    const auto& other_collider = other.get_component<BoxColliderComponent>();
    const auto& other_transform = other.get_component<TransformComponent>();

    float e_x = e_transform.previous_position.x;
    float e_y = e_transform.previous_position.y;

    float e_w = static_cast<float>(e_collider.width);

    float other_x = other_transform.previous_position.x;
    float other_y = other_transform.previous_position.y;

    float other_w = static_cast<float>(other_collider.width);

    // check if left side of e is colliding with other
    return (
        other_x < e_x + e_w &&
        other_x + other_w > e_x &&
        other_y < e_y
    );
}

bool bottom_collision(Entity e, Entity other) {
    const auto& e_collider = e.get_component<BoxColliderComponent>();
    const auto& e_transform = e.get_component<TransformComponent>();
    const auto& other_collider = other.get_component<BoxColliderComponent>();
    const auto& other_transform = other.get_component<TransformComponent>();

    float e_x = e_transform.previous_position.x;
    float e_y = e_transform.previous_position.y;

    float e_w = static_cast<float>(e_collider.width);

    float other_x = other_transform.previous_position.x;
    float other_y = other_transform.previous_position.y;

    float other_w = static_cast<float>(other_collider.width);

    // check if left side of e is colliding with other
    return (
        other_x < e_x + e_w &&
        other_x + other_w > e_x &&
        other_y > e_y
    );
}


#endif // LUA_BINDING_HPP
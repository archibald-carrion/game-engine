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

// Audio related functions

/**
 * @brief Play a sound effect.
 * @param sound_id The ID of the sound effect to play.
 */
void play_sound(const std::string& sound_id) {
    Game::get_instance().audio_manager->play_sound_effect(sound_id);
}

/**
 * @brief Play a music track.
 * @param music_id The ID of the music track to play.
 */
void play_music(const std::string& music_id) {
    Game::get_instance().audio_manager->play_music(music_id);
}

/**
 * @brief Stop all sounds and music.
 */
void stop_all_sounds() {
    Game::get_instance().audio_manager->stop_all_sounds();
}

// General entity related functions

/**
 * @brief Kill an entity.
 * @param e The entity to kill.
 */
void kill_entity(Entity e) {
    e.kill();
}

/**
 * @brief Reset the bullet.
 * @param e The bullet entity to reset.
 */
void reset_bullet(Entity e) {
    // set velocity to 0
    auto& rigid_body = e.get_component<RigidBodyComponent>();

    rigid_body.velocity = {0, 0};

    // get the player location from the game
    auto& game = Game::get_instance();
    auto [x, y] = game.player_location;

    // set the bullet location to the player location
    auto& transform = e.get_component<TransformComponent>();
    transform.position = {static_cast<float>(x), static_cast<float>(y)};
}

/**
 * @brief Update the player location.
 * @param x The x coordinate of the player.
 * @param y The y coordinate of the player.
 */
void update_player_location(int x, int y) {
    Game::get_instance().player_location = {x, y};
}

/**
 * @brief Get the tag of an entity.
 * @param e The entity to get the tag from.
 * @return The tag of the entity.
 */
std::string get_tag(Entity entity){
    return entity.get_component<TagComponent>().tag;
}

// Control related functions

/**
 * @brief Get the mouse position.
 * @return A tuple containing the x and y coordinates of the mouse.
 */
std::tuple<int, int> get_mouse_position() {
    return Game::get_instance().controller_manager->get_mouse_position();
}

/**
 * @brief Check if a mouse button is pressed.
 * @param button The button to check.
 * @return True if the button is pressed, false otherwise.
 */
bool is_mouse_button_pressed(const std::string& button) {
    return Game::get_instance().controller_manager->is_mouse_button_pressed(button);
}

/**
 * @brief Check if an action is activated.
 * @param action The action to check.
 * @return True if the action is activated, false otherwise.
 */
bool is_action_activated(const std::string& action) {
    return Game::get_instance().controller_manager->is_key_pressed(action);
}


// Movement, rotation and position related functions

/**
 * @brief Set the velocity of an entity.
 * @param e The entity to set the velocity for.
 * @param x The x component of the velocity.
 * @param y The y component of the velocity.
 */
void set_velocity(Entity e, float x, float y) {
    auto& rigid_body = e.get_component<RigidBodyComponent>();
    rigid_body.velocity.x = x;
    rigid_body.velocity.y = y;
}

/**
 * @brief Set the rotation of an entity.
 * @param e The entity to set the rotation for.
 * @param angle The angle to set the rotation to.
 */
void set_rotation(Entity e, float angle) {
    auto& transform = e.get_component<TransformComponent>();
    transform.rotation = angle;
}

/**
 * @brief Get the rotation of an entity.
 * @param e The entity to get the rotation from.
 * @return The rotation of the entity.
 */
float get_rotation(Entity e) {
    return e.get_component<TransformComponent>().rotation;
}

/**
 * @brief Get the position of an entity.
 * @param e The entity to get the position from.
 * @return A tuple containing the x and y coordinates of the entity.
 */
std::tuple<int, int> get_position(Entity e) {
    const auto& transform = e.get_component<TransformComponent>();
    return {static_cast<int>(transform.position.x), static_cast<int>(transform.position.y)};
}

/**
 * @brief Get the velocity of an entity.
 * @param e The entity to get the velocity from.
 * @return A tuple containing the x and y components of the velocity.
 */
std::tuple<int, int> get_velocity(Entity e) {
    const auto& rigid_body = e.get_component<RigidBodyComponent>();
    return {static_cast<int>(rigid_body.velocity.x), static_cast<int>(rigid_body.velocity.y)};
}

/**
 * @brief Set the position of an entity.
 * @param e The entity to set the position for.
 * @param x The x coordinate of the position.
 * @param y The y coordinate of the position.
 */
void set_position(Entity e, int x, int y) {
    auto& transform = e.get_component<TransformComponent>();
    transform.position.x = static_cast<float>(x);
    transform.position.y = static_cast<float>(y);
}

/**
 * @brief Get the size of an entity.
 * @param e The entity to get the size from.
 * @return A tuple containing the width and height of the entity.
 */
std::tuple<int, int> get_size(Entity e) {
    const auto& sprite = e.get_component<SpriteComponent>();
    const auto& transform = e.get_component<TransformComponent>();
    
    int width = sprite.width * transform.scale.x;
    int height = sprite.height * transform.scale.y;

    return {width, height};
}

// Scene related functions

/**
 * @brief Go to a scene.
 * @param scene_name The name of the scene to go to.
 */
void go_to_scene(const std::string& scene_name) {
    Game::get_instance().scene_manager->set_next_scene(scene_name);
    Game::get_instance().scene_manager->stop_scene();
}

// Collision related functions

/**
 * @brief Check if two entities are colliding from the top.
 * @param e The first entity.
 * @param other The second entity.
 * @return True if the entities are colliding from the top, false otherwise.
 */
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

/**
 * @brief Check if two entities are colliding from the left.
 * @param e The first entity.
 * @param other The second entity.
 * @return True if the entities are colliding from the left, false otherwise.
 */
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

/**
 * @brief Check if two entities are colliding from the bottom.
 * @param e The first entity.
 * @param other The second entity.
 * @return True if the entities are colliding from the bottom, false otherwise.
 */
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

/**
 * @brief Check if two entities are colliding from the right.
 * @param e The first entity.
 * @param other The second entity.
 * @return True if the entities are colliding from the right, false otherwise.
 */
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
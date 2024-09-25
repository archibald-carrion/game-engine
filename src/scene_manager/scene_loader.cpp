#include "scene_loader.hpp"

#include <iostream>
#include <glm/glm.hpp>

#include "../components/transform_component.hpp"
#include "../components/RigidBodyComponent.hpp"
#include "../components/sprite_component.hpp"
#include "../components/circle_collider_component.hpp"
#include "../components/animation_component.hpp"
#include "../components/script_component.hpp"
#include "../components/text_component.hpp"

SceneLoader::SceneLoader() {
    std::cout << "[SCENELOADER] scene loader constructor" << std::endl;

}

SceneLoader::~SceneLoader() {
    std::cout << "[SCENELOADER] scene loader destructor" << std::endl;
}

void SceneLoader::load_scene(const std::string& scene_path,
    sol::state& lua, 
    std::unique_ptr<AssetsManager>& asset_manager, 
    std::unique_ptr<ControllerManager>& controller_manager, 
    std::unique_ptr<Registry>& registry, 
    SDL_Renderer* renderer) {

    sol::load_result script_result = lua.load_file(scene_path);
    if(!script_result.valid()) {
        sol::error err = script_result;
        std::string error_message = err.what();
        std::cerr << "[SCENELOADER] " << error_message << std::endl;
        return;
    }

    lua.script_file(scene_path);
    sol::table scene = lua["scene"];

    sol::table sprites = scene["sprites"];
    load_sprites(renderer, sprites, asset_manager);

    sol::table fonts = scene["fonts"];
    load_fonts(fonts, asset_manager);

    sol::table buttons = scene["buttons"];
    load_buttons(buttons, controller_manager);

    sol::table keys = scene["keys"];
    load_keys_actions(keys, controller_manager);

    sol::table entities = scene["entities"];
    load_entities(lua, entities, registry);
}

void SceneLoader::load_sprites(SDL_Renderer* renderer, const sol::table& sprites, std::unique_ptr<AssetsManager>& asset_manager) {
    int index = 0;

    while(true) {
        sol::optional<sol::table> has_sprite = sprites[index];
        if(has_sprite == sol::nullopt) {
            break;
        }

        sol::table sprite = sprites[index];
        std::string asset_id = sprite["asset_id"];
        std::string file_path = sprite["file_path"];

        asset_manager->add_texture(renderer, asset_id, file_path);

        index++;
    }
}

void SceneLoader::load_keys_actions(const sol::table& keys, std::unique_ptr<ControllerManager>& controller_manager) {
    int index = 0;
    while(true) {
        sol::optional<sol::table> has_key = keys[index];
        if(has_key == sol::nullopt) {
            break;
        }

        sol::table key = keys[index];
        std::string name = key["name"];
        int key_code = key["key"];

        controller_manager->add_key(name, key_code);

        index++;
    }
}

void SceneLoader::load_entities(sol::state& lua, const sol::table& entities, std::unique_ptr<Registry>& registry) {
    int index = 0;

    while(true) {
        sol::optional<sol::table> has_entity = entities[index];

        if(has_entity == sol::nullopt) {
            break;
        }

        sol::table entity = entities[index];
        Entity new_entity = registry->create_entity();

        sol::optional<sol::table> has_components = entity["components"];

        if(has_components != sol::nullopt) {
            sol::table components = entity["components"];

            // Animation component, not yet implemented

            // Circle collider component
            sol::optional<sol::table> has_circle_collider = components["circular_collider"];

            if(has_circle_collider != sol::nullopt) {
                new_entity.add_component<CircleColliderComponent>(
                    components["circular_collider"]["radius"],
                    components["circular_collider"]["width"],
                    components["circular_collider"]["height"]
                );
            }

            // Rigid body component
            sol::optional<sol::table> has_rigid_body = components["rigid_body"];
            if(has_rigid_body != sol::nullopt) {
                new_entity.add_component<RigidBodyComponent>(
                    glm::vec2(
                        components["rigid_body"]["velocity"]["x"],
                        components["rigid_body"]["velocity"]["y"]
                    )
                );
            }

            // script component
            sol::optional<sol::table> has_script = components["script"];
            if( has_script != sol::nullopt) {
                lua["update"] = sol::nil;
                std::string path = components["script"]["path"];
                lua.script_file(path);

                sol::optional<sol::function> has_update = lua["update"];
                sol::function update = sol::nil;
                if(has_update != sol::nullopt) {
                    update = lua["update"];
                }

                new_entity.add_component<ScriptComponent>(update);
            }

            // Sprite component
            sol::optional<sol::table> has_sprite = components["sprite"];
            if(has_sprite != sol::nullopt) {
                new_entity.add_component<SpriteComponent>(
                    components["sprite"]["asset_id"],
                    components["sprite"]["width"],
                    components["sprite"]["height"],
                    components["sprite"]["src_rect"]["x"],
                    components["sprite"]["src_rect"]["y"]
                );
            }

            // Text component
            sol::optional<sol::table> has_text = components["text"];
            if(has_text != sol::nullopt) {
                new_entity.add_component<TextComponent>(
                    components["text"]["text"],
                    components["text"]["font_id"],
                    components["text"]["r"],
                    components["text"]["g"],
                    components["text"]["b"],
                    components["text"]["a"]
                );
            }

             // transform component
            sol::optional<sol::table> has_transform = components["transform"];
            if(has_transform != sol::nullopt) {
                new_entity.add_component<TransformComponent>(
                    glm::vec2(
                        components["transform"]["position"]["x"],
                        components["transform"]["position"]["y"]
                    ),
                    glm::vec2(
                        components["transform"]["scale"]["x"],
                        components["transform"]["scale"]["y"]
                    ),
                    components["transform"]["rotation"]
                );
            }
        }

        index++;

    }
}

void SceneLoader::load_fonts(const sol::table& fonts, std::unique_ptr<AssetsManager>& asset_manager) {
    int index = 0;
    while(true){
        sol::optional<sol::table> has_font = fonts[index];
        if(has_font == sol::nullopt) {
            break;
        }

        sol::table font = fonts[index];
        std::string font_id = font["font_id"];
        std::string file_path = font["file_path"];
        int font_size = font["font_size"];

        asset_manager->add_font(font_id, file_path, font_size);

        index++;
    }
}

void SceneLoader::load_buttons(const sol::table& buttons, std::unique_ptr<ControllerManager>& controller_manager) {
    int index = 0;
    while(true) {
        sol::optional<sol::table> has_button = buttons[index];
        if(has_button == sol::nullopt) {
            break;
        }

        sol::table button = buttons[index];

        std::string button_name = button["name"];
        int button_code = button["button_code"];

        controller_manager->add_mouse_button(button_name, button_code);

        index++;
    }
}
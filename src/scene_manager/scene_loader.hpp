#ifndef SCENE_LOADER_HPP
#define SCENE_LOADER_HPP

#include <memory>
#include <string>
#include <SDL2/SDL.h>
#include <sol/sol.hpp>

#include "../assets_manager/assets_manager.hpp"
#include "../controller_manager/controller_manager.hpp"
#include "../ECS/ECS.hpp"

class SceneLoader {
private:
    void load_sounds(const sol::table& sounds, std::unique_ptr<AssetsManager>& asset_manager);
    
    void load_sprites(SDL_Renderer* renderer, const sol::table& sprites, std::unique_ptr<AssetsManager>& asset_manager);

    void load_fonts(const sol::table& fonts, std::unique_ptr<AssetsManager>& asset_manager);
    
    void load_buttons(const sol::table& buttons, std::unique_ptr<ControllerManager>& controller_manager);

    void load_keys_actions(const sol::table& keys, std::unique_ptr<ControllerManager>& controller_manager);

    void load_entities(sol::state& lua, const sol::table& entities, std::unique_ptr<Registry>& registry);

public:
    SceneLoader();
    ~SceneLoader();
    void load_scene(const std::string& scene_path,
        sol::state& lua, 
        std::unique_ptr<AssetsManager>& asset_manager, 
        std::unique_ptr<ControllerManager>& controller_manager, 
        std::unique_ptr<Registry>& registry, 
        SDL_Renderer* renderer);

};



#endif // SCENE_LOADER_HPP
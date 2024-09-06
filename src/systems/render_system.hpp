#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include <iostream>
#include "SDL2/SDL.h"
#include "../assets_manager/assets_manager.hpp"
#include "../components/sprite_component.hpp"
#include "../components/transform_component.hpp"
#include "../ECS/ECS.hpp"

class RenderSystem: public System {
public:
    RenderSystem() {
        std::cout<<"RenderSystem constructor"<<std::endl;
        RequireComponent<SpriteComponent>();
        RequireComponent<TransformComponent>();
    }

    void update(SDL_Renderer* renderer, const std::unique_ptr<AssetsManager>& asset_manager) {

        for(auto entity: get_entities()) {
            const auto sprite = entity.get_component<SpriteComponent>();
            const auto transform = entity.get_component<TransformComponent>();

            SDL_Rect src_rect = sprite.src_rect;
            SDL_Rect dst_rect = {
                static_cast<int>(transform.position.x),
                static_cast<int>(transform.position.y),
                static_cast<int>(sprite.width * transform.scale.x),
                static_cast<int>(sprite.height * transform.scale.y)
            };

            SDL_RenderCopyEx(
                renderer, 
                asset_manager->get_texture(sprite.texture_id),
                &src_rect, 
                &dst_rect, 
                transform.rotation,
                NULL, // is centered
                SDL_FLIP_NONE // is mirror
            );
        }
    }
};


#endif // RENDER_SYSTEM_HPP
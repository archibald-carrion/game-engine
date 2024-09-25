#ifndef RENDER_TEXT_SYSTEM_HPP
#define RENDER_TEXT_SYSTEM_HPP

#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../components/text_component.hpp"
#include "../components/transform_component.hpp"
#include "../assets_manager/assets_manager.hpp"
#include "../ECS/ECS.hpp"

class RenderTextSystem : public System {
public:
    RenderTextSystem() {
        RequireComponent<TextComponent>();
        RequireComponent<TransformComponent>();
    }

    void update(SDL_Renderer* renderer, const std::unique_ptr<AssetsManager>& assets_manager) {
        for(auto entity : get_entities()) {
            auto& text = entity.get_component<TextComponent>();
            auto& transform = entity.get_component<TransformComponent>();

        	// create the surface
            SDL_Surface* surface = TTF_RenderText_Blended(
                assets_manager->get_font(text.font_id),
                text.text.c_str(),
                text.color
            );

            text.width = surface->w;
            text.height = surface->h;
            // create the texture
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            // free the surface
            SDL_FreeSurface(surface);

            SDL_Rect destionation_rect = {
                static_cast<int>(transform.position.x),
                static_cast<int>(transform.position.y),
                text.width * static_cast<int>(transform.scale.x),
                text.height  * static_cast<int>(transform.scale.y)
            };

            SDL_RenderCopy(renderer, texture, NULL, &destionation_rect);
            SDL_DestroyTexture(texture);
        }
    }
};

#endif // RENDER_TEXT_SYSTEM_HPP
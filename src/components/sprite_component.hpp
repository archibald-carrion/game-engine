#ifndef SPRITE_COMPONENT_HPP
#define SPRITE_COMPONENT_HPP

#include <SDL2/SDL.h>
#include <string>

struct SpriteComponent {
    std::string texture_id;
    int height;
    int width;
    SDL_Rect src_rect;

    SpriteComponent(const std::string& texture_id = "none", int width = 0, int height = 0, int src_rect_X =0, int src_rect_Y = 0) {
        this->texture_id = texture_id;
        this->height = height;
        this->width = width;
        this->src_rect = {src_rect_X, src_rect_Y, width, height};
    }
};



#endif // SPRITE_COMPONENT_HPP
#ifndef TEXT_COMPONENT_HPP
#define TEXT_COMPONENT_HPP

#include <SDL2/SDL.h>
#include <string>


struct TextComponent {
    std::string text;
    std::string font_id;
    SDL_Color color;
    int width;
    int height;

    TextComponent(const std::string& text = "", const std::string& font_id = "", u_char r = 0, u_char g = 0, u_char b = 0,u_char a = 0) {
        this->text = text;
        this->font_id = font_id;
        this->color.r = r;
        this->color.g = g;
        this->color.b = b;
        this->color.a = a;
        this->width = 0;
        this->height = 0;
    }
};

#endif // TEXT_COMPONENT_HPP
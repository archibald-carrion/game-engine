#include "assets_manager.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

Assets_manager::Assets_manager() {
    std::cout << "Assets_manager constructor" << std::endl;
}

Assets_manager::~Assets_manager() {
    std::cout << "Assets_manager destructor" << std::endl;
}

void Assets_manager::clear_assets() {
    for (auto texture : textures) {
        SDL_DestroyTexture(texture.second);
    }

    // add other loop for assets which are not texture, like audio and such

    textures.clear();
}

void Assets_manager::add_texture(SDL_Renderer* renderer, const std::string& texture_id, const std::string& file_path) {
    SDL_Surface* surface = IMG_Load(file_path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    textures.emplace(texture_id, texture);
}

SDL_Texture* Assets_manager::get_texture(const std::string& texture_id) {
    return textures[texture_id];
}
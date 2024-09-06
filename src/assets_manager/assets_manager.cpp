#include "assets_manager.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

AssetsManager::AssetsManager() {
    std::cout << "AssetsManager constructor" << std::endl;
}

AssetsManager::~AssetsManager() {
    std::cout << "AssetsManager destructor" << std::endl;
}

void AssetsManager::clear_assets() {
    for (auto texture : textures) {
        SDL_DestroyTexture(texture.second);
    }

    // add other loop for assets which are not texture, like audio and such

    textures.clear();
}

void AssetsManager::add_texture(SDL_Renderer* renderer, const std::string& texture_id, const std::string& file_path) {
    SDL_Surface* surface = IMG_Load(file_path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    textures.emplace(texture_id, texture);
}

SDL_Texture* AssetsManager::get_texture(const std::string& texture_id) {
    return textures[texture_id];
}
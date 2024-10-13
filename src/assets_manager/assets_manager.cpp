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
    // clear textures
    for (auto texture : textures) {
        SDL_DestroyTexture(texture.second);
    }

    // clear fonts
    for (auto font : fonts) {
        TTF_CloseFont(font.second);
    }

        // clear sounds
    for (auto sound : sounds) {
        Mix_FreeChunk(sound.second);
    }


    // add other loop for assets which are not texture, like audio and such
    sounds.clear();
    fonts.clear();
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

void  AssetsManager::add_font(const std::string& font_id, const std::string& file_path, int font_size) {
    TTF_Font* font = TTF_OpenFont(file_path.c_str(), font_size);

    // check if font is null
    if (font == nullptr) {
        std::cerr << "[ASSETMANAGER] Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }
    this->fonts.emplace(font_id, font);
}

TTF_Font*  AssetsManager::get_font(const std::string& font_id) {

    return fonts[font_id];

}

void AssetsManager::add_sound(const std::string& sound_id, const std::string& file_path) {
    Mix_Chunk* sound = Mix_LoadWAV(file_path.c_str());

    // check if sound is null
    if (sound == nullptr) {
        std::cerr << "[ASSETMANAGER] Failed to load sound: " << Mix_GetError() << std::endl;
        return;
    }
    this->sounds.emplace(sound_id, sound);
}

Mix_Chunk* AssetsManager::get_sound(const std::string& sound_id) {
    return sounds[sound_id];
}
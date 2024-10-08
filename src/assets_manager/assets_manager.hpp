#ifndef ASSETS_MANAGER_HPP
#define ASSETS_MANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <map>
#include <string>

class AssetsManager {
private:
    std::map<std::string, SDL_Texture*> textures;
    std::map<std::string, TTF_Font*> fonts;

public: 
    AssetsManager();
    ~AssetsManager();

    void clear_assets();

    void add_texture(SDL_Renderer* rendere, const std::string& texture_id, const std::string& file_path);

    SDL_Texture* get_texture(const std::string& texture_id);

    void add_font(const std::string& font_id, const std::string& file_path, int font_size);

    TTF_Font* get_font(const std::string& font_id);
};




#endif // ASSETS_MANAGER_HPP
#ifndef ASSETSMANAGER_HPP
#define ASSETSMANAGER_HPP

#include <SDL2/SDL.h>

#include <map>
#include <string>

class Assets_manager {
private:
    std::map<std::string, SDL_Texture*> textures;
public: 
    Assets_manager();
    ~Assets_manager();

    void clear_assets();

    void add_texture(SDL_Renderer* rendere, const std::string& texture_id, const std::string& file_path);

    SDL_Texture* get_texture(const std::string& texture_id);
};




#endif // ASSETSMANAGER_HPP
#ifndef GAME_H
#define GAME_H

#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <fstream> // used to read the configuration file

#include "../configuration.hpp"



class Game {
private:
    void processInput();
    void update();
    void render();

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning;
    window_data window_configuration;
    window_font_config window_font;
    std::vector<entity*> entities;
    
    // TTF_Font* font_ = nullptr;
    // int font_size = 0;
    // SDL_Color font_color = {0, 0, 0, 255};
    // std::string message = "Hello, World!";
    // glm::vec2 message_position = glm::vec2(10.0f, 10.0f);
    // size_t message_width = 0;
    // size_t message_height = 0;
    // SDL_Texture* message_texture = nullptr;
    // double message_rotation = 0.0;


public:
    Game();
    ~Game();
    void init();
    void run();
    void destroy();
    void print_game_data();

};

#endif // GAME_H
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
    window_font font;
    std::vector<entity*> entities;

public:
    Game();
    ~Game();
    void init();
    void run();
    void destroy();
    void print_game_data();

};

#endif // GAME_H
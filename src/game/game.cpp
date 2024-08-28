#include "game.hpp"
#include <iostream>

Game::Game() {
    std::cout << "Game constructor" << std::endl;
}

Game::~Game() {
    std::cout << "Game destructor" << std::endl;
}

void Game::init() {
    std::cout << "Game init" << std::endl;
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    // read the config file
    read_configuration_file(&window_configuration, &font, &entities);

    // create the window
    this->window = SDL_CreateWindow(
        "pseudo engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_configuration.width,
        window_configuration.height,
        SDL_WINDOW_SHOWN
    );

    // create renderer
    this->renderer = SDL_CreateRenderer(
        this->window, 
        -1, // screen driver index
        0 // no flags
    );

    this->isRunning = true;

    // TODO: this could be improved by passing the renderer to the configuration
    // manager and loading the textures there when reading the configuration file

    // for each entity, load the texture and create the rect
    for (auto& e : entities) {
        // load the texture
        SDL_Surface* surface = IMG_Load(e->sprite_folder.c_str());
        if (surface == nullptr) {
            std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl;
            return;
        }
        e->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
        SDL_FreeSurface(surface);

        // create the rect
        e->srcRect = new SDL_Rect();
        // set the position of the rect and its dimensions
        e->srcRect->x = 0; // if I work with spritesheets, I will need to change this, but for now it's fine
        e->srcRect->y = 0;
        e->srcRect->w = e->sprite_width;
        e->srcRect->h = e->sprite_height;

        e->dstRect = new SDL_Rect();
        e->dstRect->x = e->pos_X;
        e->dstRect->y = e->pos_Y;
        e->dstRect->w = e->sprite_width;
        e->dstRect->h = e->sprite_height;
    }
}

void Game::run() {
    // std::cout << "Game run" << std::endl;

    while (isRunning) {
        processInput();
        update();
        render();
    }
}

void Game::destroy() {
    std::cout << "Game destroy" << std::endl;
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();

    // free allocated memory
    // TODO: move this to ~Game() ?
    delete window_configuration.window_color;
    delete font.font_color;
    for (auto& e : entities) {
        delete e; // Deallocate each entity
    }
}

void Game::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            // close the window events
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    isRunning = false;
                }
                // add case to pause game on pressing p
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    // std::cout << "Game update" << std::endl;
}

void Game::render() {
    // std::cout << "Game render" << std::endl;
    
    // clear the window
    SDL_SetRenderDrawColor(
        this->renderer,
        this->window_configuration.window_color->r,
        this->window_configuration.window_color->g,
        this->window_configuration.window_color->b,
        SDL_ALPHA_OPAQUE
    );

    SDL_RenderClear(this->renderer);

    // render the entities
    for (const auto& e : this->entities) {
        SDL_RenderCopyEx(
            this->renderer,
            e->texture,
            e->srcRect, // source rect, could be nullptr to render the entire texture
            e->dstRect, // destination rect
            e->rotation,
            nullptr, // center of rotation, nullptr to rotate around the center of the rect
            SDL_FLIP_NONE
        );
    }


    SDL_RenderPresent(this->renderer);
}

void Game::print_game_data() {
    // print the content of the window configuration settings
    std::cout << "width of the window: " 
        << this->window_configuration.width << ", height of the window: " 
        << this->window_configuration.height << std::endl;
    std::cout << "color of the window: (" 
        << unsigned(this->window_configuration.window_color->r) << ", " 
        << unsigned(this->window_configuration.window_color->g) << ", " 
        << unsigned(this->window_configuration.window_color->b) << ")" << std::endl;

    // print the content of the font configuration settings
    std::cout << "ttf file: " << font.font_folder << std::endl;
    std::cout << "font size: " << unsigned(font.font_size) << std::endl;
    std::cout << "color of the font: (" 
        << unsigned(this->font.font_color->r) << ", "
        << unsigned(this->font.font_color->g) << ", "
        << unsigned(this->font.font_color->b) << ")" << std::endl;

    // print the entities information
    for (const auto& e : this->entities) {
        std::cout << "Label: " << e->label << ", Position: (" << e->pos_X << ", " << e->pos_Y << ")" << std::endl;
        std::cout << "rotation: " << e->rotation << ", speed: (" << e->speed_X << ", " << e->speed_Y << ")" << std::endl;
        std::cout << "sprite dirr: " << e->sprite_folder << ", sprite dimensions: " << e->sprite_width << ", " << e->sprite_height << std::endl;
    }
}
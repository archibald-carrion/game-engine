/**
 * @file game.h
 * @brief Defines the Game class and related constants for the game engine.
 */

#ifndef GAME_H
#define GAME_H

#include <sol/sol.hpp>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <fstream> // used to read the configuration file
#include <memory>

#include "../ECS/ECS.hpp"
#include "../utils/configuration.hpp"
#include "../assets_manager/assets_manager.hpp"
#include "../event_manager/event_manager.hpp"
#include "../controller_manager/controller_manager.hpp"



/** @brief Target frames per second for the game. */
const int FPS = 60;

/** @brief Number of milliseconds per frame based on the target FPS. */
const int MILLISECS_PER_FRAME = 1000 / FPS;


/**
 * @class Game
 * @brief Main game class that handles initialization, game loop, and cleanup.
 */
class Game {
private:
    /**
     * @brief Default constructor for the Game class.
     */
    Game();

    /**
     * @brief Destructor for the Game class.
     */
    ~Game();

    /**
     * @brief Processes user input events.
     */
    void processInput();

    /**
     * @brief Updates the game state.
     */
    void update();

    /**
     * @brief Renders the game state to the screen.
     */
    void render();

    /**
     * @brief 
     */
    void setup();

    SDL_Window* window = nullptr; /**< Pointer to the SDL window. */
    SDL_Renderer* renderer = nullptr; /**< Pointer to the SDL renderer. */

    bool isRunning; /**< Flag to indicate if the game is running. */
    int mPreviousFrame = 0; /**< Time of the previous frame. */
    bool isPaused = false; /**< Flag to indicate if the game is paused. */

    window_data window_configuration; /**< Window configuration data. */
    window_font_config window_font; /**< Font configuration data. */
    std::vector<entity*> entities; /**< Vector of entity pointers. */

    std::unique_ptr<Registry> registry; /**< Pointer to the game registry. */
    std::unique_ptr<AssetsManager> assets_manager;
    std::unique_ptr<EventManager> events_manager;

    sol::state lua; /**< Lua state for scripting. */

 
public:
    std::unique_ptr<ControllerManager> controller_manager;

    /**
     * @brief Initializes the game engine.
     */
    void init();

    /**
     * @brief Runs the game loop.
     */
    void run();

    /**
     * @brief Destroys the game engine and cleans up resources.
     */
    void destroy();

    /**
     * @brief Prints the game data to the console.
     */
    void print_game_data();

    /**
     * @brief Returns the instance of the Game class.
     */
    static Game& get_instance();

};

#endif // GAME_H
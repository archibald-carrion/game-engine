/**
 * @file game.h
 * @brief Defines the Game class and related constants for the game engine.
 */

#ifndef GAME_H
#define GAME_H

#include <sol/sol.hpp> // Lua scripting
#include <glm/glm.hpp> // GLM math library
#include <SDL2/SDL.h> // SDL library for window creation and rendering
#include <SDL2/SDL_image.h> // SDL image library for loading images
#include <SDL2/SDL_ttf.h> // SDL ttf library for rendering text
#include <fstream> // used to read the configuration file
#include <memory> // used for smart pointers

#include "../ECS/ECS.hpp" // ECS library for entity-component-system
// #include "../utils/configuration.hpp" // Configuration data structures
#include "../assets_manager/assets_manager.hpp" // Assets manager for loading textures and fonts
#include "../event_manager/event_manager.hpp" // Event manager for handling events
#include "../controller_manager/controller_manager.hpp" // Controller manager for handling user input
#include "../scene_manager/scene_manager.hpp" // Scene manager for handling scenes



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
     * @brief setup the game engine.
     */
    void setup();

    /**
     * @brief Run the scene.
     */
    void run_scene();

    // /**
    //  * @brief Toggle the fullscreen mode.
    //  */
    // void toggleFullscreen();

    SDL_Window* window = nullptr; /**< Pointer to the SDL window. */

    SDL_Rect camera = {0, 0, 0, 0};

    // int window_height = 0;
    // int window_width = 0;



    bool isRunning; /**< Flag to indicate if the game is running. */
    int mPreviousFrame = 0; /**< Time of the previous frame. */
    bool isPaused = false; /**< Flag to indicate if the game is paused. */

    //window_data window_configuration; /**< Window configuration data. */
    //window_font_config window_font; /**< Font configuration data. */
    // std::vector<entity*> entities; /**< Vector of entity pointers. */

 
public:
    // bool isFullscreen = false;

    int map_height = 0;
    int map_width = 0;

    int WINDOW_WIDTH = 800;
    int WINDOW_HEIGHT = 600; 
    
    SDL_Renderer* renderer = nullptr; /**< Pointer to the SDL renderer. */
    std::unique_ptr<Registry> registry; /**< Pointer to the game registry. */
    std::unique_ptr<SceneManager> scene_manager; /**< Pointer to the scene manager. */
    std::unique_ptr<AssetsManager> assets_manager; /**< Pointer to the assets manager. */
    std::unique_ptr<EventManager> events_manager; /**< Pointer to the event manager. */
    std::unique_ptr<ControllerManager> controller_manager; /**< Pointer to the controller manager. */
    sol::state lua; /**< Lua state for scripting. */

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
#include "game.hpp"
#include <iostream>

#include "../systems/render_system.hpp"
#include "../systems/MovementSystem.hpp"
#include "../systems/circle_collision_system.hpp"
// #include "../systems/damage_system.hpp"
#include "../systems/animation_system.hpp"
#include "../systems/script_system.hpp"
#include "../systems/render_text_system.hpp"
#include "../systems/UI_system.hpp"
#include "../systems/camera_movement_system.hpp"
#include "../systems/box_collision_system.hpp"

// #include "../components/transform_component.hpp"
// #include "../components/RigidBodyComponent.hpp"
// #include "../components/sprite_component.hpp"
// #include "../components/circle_collider_component.hpp"
// #include "../components/animation_component.hpp"
// #include "../components/script_component.hpp"
// #include "../components/text_component.hpp"

#include "../events/click_event.hpp"

Game::Game() {
    std::cout << "Game constructor" << std::endl;
    registry = std::make_unique<Registry>();
    assets_manager = std::make_unique<AssetsManager>();
    events_manager = std::make_unique<EventManager>();
    controller_manager = std::make_unique<ControllerManager>();
    scene_manager = std::make_unique<SceneManager>();
}

Game::~Game() {
    std::cout << "Game destructor" << std::endl;
    
    // free allocated memory
    // delete window_configuration.window_color;
    // delete window_font.font_color;
    // for (auto& e : entities) {
    //     delete e; // Deallocate each entity
    // }

    scene_manager.reset();
    assets_manager.reset();
    events_manager.reset();
    controller_manager.reset();
    registry.reset();
    
}

void Game::setup() {
    registry->add_system<RenderSystem>();
    // registry->add_system<DamageSystem>();
    registry->add_system<MovementSystem>();
    registry->add_system<CircleCollisionSystem>();
    registry->add_system<AnimationSystem>();
    registry->add_system<ScriptSystem>();
    registry->add_system<RenderTextSystem>();
    registry->add_system<UISystem>();
    registry->add_system<CameraMovementSystem>();
    registry->add_system<BoxCollisionSystem>();

    scene_manager->load_scene_from_script("assets/scripts/scenes.lua", lua);

    lua.open_libraries(sol::lib::base, sol::lib::math);
    registry->get_system<ScriptSystem>().create_lua_binding(lua);
}

Game& Game::get_instance() {
    static Game game;
    return game;
}

void Game::init() {
    std::cout << "Game init" << std::endl;
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }


    // read the config file
    // read_configuration_file(&window_configuration, &window_font, &entities);

    this->map_height = 2000;
    this->map_width = 2000;

    // create the window
    this->window = SDL_CreateWindow(
        "pseudo engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    SDL_SetWindowResizable(window, SDL_FALSE);

    // create renderer
    this->renderer = SDL_CreateRenderer(
        this->window, 
        -1, // screen driver index
        0 // no flags
    );

    camera.x = 0;
    camera.y = 0;
    camera.w = WINDOW_WIDTH; //window_configuration.width;
    camera.h = WINDOW_HEIGHT; // window_configuration.height;

    this->isRunning = true;

    // TODO: this could be improved by passing the renderer to the configuration
    // manager and loading the textures there when reading the configuration file

    if (TTF_Init() != 0) {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return;
    }

    // // initialize the text
    // window_font.font = TTF_OpenFont(window_font.font_folder.c_str(), window_font.font_size);
    // if (window_font.font == nullptr) {
    //     std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    //     return;
    // }

    // for each entity, load the texture and create the rect
    /*for (auto& e : entities) {
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

        // create the message texture
        SDL_Surface* surface_message = TTF_RenderText_Solid(
            window_font.font,
            e->label.c_str(),
            SDL_Color{window_font.font_color->r, window_font.font_color->g, window_font.font_color->b, window_font.font_color->alpha}
        );
        e->message_texture = SDL_CreateTextureFromSurface(this->renderer, surface_message);
        // set size and position of the message
        e->message_width = surface_message->w;
        e->message_height = surface_message->h;
        // position the message in the center of the entity
        e->message_position = glm::vec2(e->pos_X + e->sprite_width / 2 - e->message_width / 2, e->pos_Y + e->sprite_height / 2 - e->message_height / 2);
        SDL_FreeSurface(surface_message);
    }*/
}

void Game::run() {
    setup();

    while (isRunning) {
        scene_manager->start_scene();
        run_scene();
    }
}

void Game::run_scene() {
    scene_manager->load_scene();
    while(scene_manager->is_current_scene_running()) {
        processInput();
        update();
        render();
    }
    assets_manager->clear_assets();
    registry->clear_all_entities();
}

void Game::destroy() {
    std::cout << "Game destroy" << std::endl;

    // destroy the texture of each entity
    // for (auto& e : entities) {
    //     SDL_DestroyTexture(e->texture); // free the texture
    //     SDL_DestroyTexture(e->message_texture); // free the texture
    // }

    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    
    TTF_Quit();
    SDL_Quit();
}

void Game::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            // close the window events
            case SDL_QUIT:
                scene_manager->stop_scene();
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                // manage the fullscreen event
                // if (event.key.keysym.sym == SDLK_F11 || 
                //     (event.key.keysym.sym == SDLK_RETURN && 
                //      event.key.keysym.mod & KMOD_ALT)) {
                //     toggleFullscreen();
                // }

                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    scene_manager->stop_scene();
                    isRunning = false;
                    break;
                }else if (event.key.keysym.sym == SDLK_p)
                {
                    isPaused = !isPaused;
                    break;
                }
                controller_manager->set_key_to_pressed(event.key.keysym.sym);          
                 
                break;

            case SDL_KEYUP:
                controller_manager->set_key_to_up(event.key.keysym.sym);
                break;

            case SDL_MOUSEMOTION:
                int x, y;
                SDL_GetMouseState(&x, &y);
                controller_manager->set_mouse_position(x, y);

                break;
            case SDL_MOUSEBUTTONDOWN:
                controller_manager->set_mouse_position(event.button.x, event.button.y);
                controller_manager->set_mouse_button_to_pressed(static_cast<int>(event.button.button));
                std::cout << (int)event.button.button << std::endl;
                events_manager->emit_event<ClickEvent>(static_cast<int>(event.button.button), event.button.x, event.button.y);
                break;
            case SDL_MOUSEBUTTONUP:
                controller_manager->set_mouse_position(event.button.x, event.button.y);
                controller_manager->set_mouse_button_to_up(static_cast<int>(event.button.button));
                break;
            default:
                break;
                
        }
    }
}

void Game::update() {

    if (isPaused) {
        this->mPreviousFrame = SDL_GetTicks();
        return;
    }

    int time_to_wait = MILLISECS_PER_FRAME - (SDL_GetTicks() - this->mPreviousFrame);

    if (time_to_wait > 0 && time_to_wait <= MILLISECS_PER_FRAME) {
        SDL_Delay(time_to_wait);
    }

    // calculate the time between frames
    double deltaTime = (SDL_GetTicks() - this->mPreviousFrame) / 1000.0;
    // TOOD: add variableto LUA state

    this->mPreviousFrame = SDL_GetTicks();

    // re-initialize subscriptions
    events_manager->reset();
    // registry->get_system<DamageSystem>().subscribe_to_collision_event(events_manager);
    registry->get_system<UISystem>().suscribe_to_click_event(events_manager);

    registry->update();
    registry->get_system<ScriptSystem>().update(lua);
    registry->get_system<AnimationSystem>().update();
    registry->get_system<MovementSystem>().Update(deltaTime);
    registry->get_system<CameraMovementSystem>().update(this->camera);
    registry->get_system<CircleCollisionSystem>().update(events_manager);
    registry->get_system<BoxCollisionSystem>().update(lua);

    // on each frame update the position of the entities based on their speed
    /*for (auto& e : entities) {
        e->pos_X += e->speed_X * deltaTime;
        e->pos_Y += e->speed_Y * deltaTime;

        // Update the destination rectangle to match the new position
        e->dstRect->x = static_cast<int>(e->pos_X);
        e->dstRect->y = static_cast<int>(e->pos_Y);

        // Update the position of the message
        e->message_position = glm::vec2(e->pos_X + e->sprite_width / 2 - e->message_width / 2, 
                                        e->pos_Y + e->sprite_height / 2 - e->message_height / 2);

        // Check for collisions with window borders
        if (e->pos_X < 0 || e->pos_X + e->sprite_width > window_configuration.width) {
            e->speed_X *= -1;
        }
        if (e->pos_Y < 0 || e->pos_Y + e->sprite_height > window_configuration.height) {
            e->speed_Y *= -1;
        }
    }*/
}

void Game::render() {
    // clear the window
    // SDL_SetRenderDrawColor(
    //     this->renderer,
    //     this->window_configuration.window_color->r,
    //     this->window_configuration.window_color->g,
    //     this->window_configuration.window_color->b,
    //     SDL_ALPHA_OPAQUE
    // );

    SDL_RenderClear(this->renderer);

    // render the entities
    /*for (const auto& e : this->entities) {
        SDL_RenderCopyEx(
            this->renderer,
            e->texture,
            e->srcRect, // source rect, could be nullptr to render the entire texture
            e->dstRect, // destination rect
            e->rotation,
            nullptr, // center of rotation, nullptr to rotate around the center of the rect
            SDL_FLIP_NONE
        );

        // render the text
        SDL_RenderCopyEx(
            this->renderer,
            e->message_texture,
            nullptr, // source rect, nullptr to render the entire texture
            new SDL_Rect{int(e->message_position.x), int(e->message_position.y), int(e->message_width), int(e->message_height)}, // destination rect
            0.0,
            nullptr, // center of rotation, nullptr to rotate around the center of the rect
            SDL_FLIP_NONE
        );
    }*/

    registry->get_system<RenderSystem>().update(renderer, assets_manager, this->camera);
    registry->get_system<RenderTextSystem>().update(renderer, assets_manager);

    SDL_RenderPresent(this->renderer);
}

// void Game::toggleFullscreen() {
//     isFullscreen = !isFullscreen;
//     SDL_SetWindowFullscreen(window, isFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
// }

/*void Game::print_game_data() {
    // print the content of the window configuration settings
    std::cout << "width of the window: " 
        << this->window_configuration.width << ", height of the window: " 
        << this->window_configuration.height << std::endl;
    std::cout << "color of the window: (" 
        << unsigned(this->window_configuration.window_color->r) << ", " 
        << unsigned(this->window_configuration.window_color->g) << ", " 
        << unsigned(this->window_configuration.window_color->b) << ")" << std::endl;

    // print the content of the font configuration settings
    std::cout << "ttf file: " << window_font.font_folder << std::endl;
    std::cout << "font size: " << unsigned(window_font.font_size) << std::endl;
    std::cout << "color of the font: (" 
        << unsigned(this->window_font.font_color->r) << ", "
        << unsigned(this->window_font.font_color->g) << ", "
        << unsigned(this->window_font.font_color->b) << ")" << std::endl;

    // print the entities information
    for (const auto& e : this->entities) {
        std::cout << "Label: " << e->label << ", Position: (" << e->pos_X << ", " << e->pos_Y << ")" << std::endl;
        std::cout << "rotation: " << e->rotation << ", speed: (" << e->speed_X << ", " << e->speed_Y << ")" << std::endl;
        std::cout << "sprite dirr: " << e->sprite_folder << ", sprite dimensions: " << e->sprite_width << ", " << e->sprite_height << std::endl;
    }
}*/
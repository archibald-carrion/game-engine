/**
 * @file game_config.h
 * @brief Contains structures and functions for game configuration.
 */

#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <glm/glm.hpp>

/**
 * @struct color
 * @brief Represents an RGBA color.
 */
struct color {
    uint8_t r;    /**< Red component */
    uint8_t g;    /**< Green component */
    uint8_t b;    /**< Blue component */
    uint8_t alpha;/**< Alpha (transparency) component */
};

/**
 * @struct window_data
 * @brief Contains configuration data for the game window.
 */
struct window_data {
    uint32_t width;           /**< Width of the window */
    uint32_t height;          /**< Height of the window */
    color* window_color;      /**< Pointer to the window background color */
};

/**
 * @struct window_font_config
 * @brief Contains configuration data for the font used in the game.
 */
struct window_font_config {
    std::string font_folder;  /**< Path to the font file */
    color* font_color;        /**< Pointer to the font color */
    uint8_t font_size;        /**< Font size */
    TTF_Font* font;           /**< Pointer to the loaded TTF_Font */
};

/**
 * @struct entity
 * @brief Represents an entity in the game.
 */
struct entity {
    std::string label;        /**< Label or name of the entity */
    std::string sprite_folder;/**< Path to the sprite image */
    uint32_t sprite_width;    /**< Width of the sprite */
    uint32_t sprite_height;   /**< Height of the sprite */
    double pos_X;             /**< X-coordinate of the entity's position */
    double pos_Y;             /**< Y-coordinate of the entity's position */
    int32_t speed_X;          /**< Horizontal speed of the entity */
    int32_t speed_Y;          /**< Vertical speed of the entity */
    double rotation;          /**< Rotation of the entity in radians */
    SDL_Texture* texture;     /**< Pointer to the entity's texture */
    SDL_Rect* srcRect;        /**< Source rectangle for rendering */
    SDL_Rect* dstRect;        /**< Destination rectangle for rendering */

    SDL_Texture* message_texture; /**< Pointer to the message texture */
    SDL_Rect* message_dstRect;    /**< Destination rectangle for the message */
    size_t message_width;         /**< Width of the message */
    size_t message_height;        /**< Height of the message */
    glm::vec2 message_position;   /**< Position of the message */
};

/**
 * @brief Reads the configuration file and populates the provided structures.
 * 
 * @param window_config Pointer to the window_data structure to be populated
 * @param font Pointer to the window_font_config structure to be populated
 * @param entities Pointer to the vector of entity pointers to be populated
 */
void read_configuration_file(window_data* window_config, window_font_config* font, std::vector<entity*>* entities);

#endif // GAME_CONFIG_H
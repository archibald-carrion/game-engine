#ifndef PLAYER_SCORE_SYSTEM_HPP
#define PLAYER_SCORE_SYSTEM_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdexcept>
#include <string>

#include "../ECS/ECS.hpp"
#include "../components/player_score_component.hpp"
#include "../assets_manager/assets_manager.hpp"

/**
 * @brief PlayerScoreSystem class
 * The PlayerScoreSystem class is responsible for rendering player scores in the top-right corner.
 */
class PlayerScoreSystem : public System {
private:
    TTF_Font* font;
    const int FONT_SIZE = 32;
    const char* FONT_PATH = "./assets/fonts/ARCADECLASSIC.TTF";  // Adjust path as needed
    const int MARGIN = 20;  // Margin from the screen edges
     const char* SCORE_PREFIX = "Score  ";  // Prefix text for the score

public:
    /**
     * @brief Constructor for PlayerScoreSystem
     * Initializes the TTF system and loads the font
     */
    PlayerScoreSystem() {
        RequireComponent<PlayerScore>();

        // Initialize SDL_TTF
        if (TTF_Init() == -1) {
            throw std::runtime_error("Failed to initialize SDL_TTF: " + std::string(TTF_GetError()));
        }

        // Load the font
        font = TTF_OpenFont(FONT_PATH, FONT_SIZE);
        if (!font) {
            TTF_Quit();
            throw std::runtime_error("Failed to load font: " + std::string(TTF_GetError()));
        }
    }

    /**
     * @brief Destructor for PlayerScoreSystem
     * Cleans up the font and TTF system
     */
    ~PlayerScoreSystem() {
        if (font) {
            TTF_CloseFont(font);
        }
        TTF_Quit();
    }

    /**
     * @brief Update the player score system
     * @param renderer The SDL renderer to use for drawing
     */
    void update(SDL_Renderer* renderer) {
        if (!font || !renderer) {
            return;
        }

        // Get window size
        int window_width, window_height;
        SDL_GetRendererOutputSize(renderer, &window_width, &window_height);

        for (auto entity : get_entities()) {
            auto& score = entity.get_component<PlayerScore>();
            
            // Convert score to string
            std::string score_text = std::string(SCORE_PREFIX) + std::to_string(score.player_score);

            
            // Create surface with score text
            SDL_Surface* surface = TTF_RenderText_Blended(
                font,
                score_text.c_str(),
                SDL_Color{255, 255, 255, 255}  // White color
            );

            if (!surface) {
                std::cerr << "Failed to render text: " << TTF_GetError() << std::endl;
                continue;
            }

            // Create texture from surface
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            
            if (!texture) {
                SDL_FreeSurface(surface);
                continue;
            }

            // Calculate position in top-right corner
            SDL_Rect dest_rect = {
                window_width - surface->w - MARGIN,  // Right-aligned with margin
                MARGIN,                              // Top margin
                surface->w,
                surface->h
            };

            // Render the score
            SDL_RenderCopy(renderer, texture, nullptr, &dest_rect);

            // Clean up
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
    }

};

#endif // PLAYER_SCORE_SYSTEM_HPP
#include "Pseudo3DGame.hpp"
Pseudo3DGame::Pseudo3DGame() {
    std::cout << "Constructor of Pseudo3DGame" << std::endl;
}

Pseudo3DGame::~Pseudo3DGame() {
    std::cout << "Destructor of Pseudo3DGame" << std::endl;

    for (auto texture : textures) {
        SDL_DestroyTexture(texture);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Pseudo3DGame::init() {
    this->isRunning = true;
    this->movement_speed = 0.1;

    std::cout << "Game init" << std::endl;
    // initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    load_textures();


    this->window = SDL_CreateWindow(
        "pseudo engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    // create renderer
    this->renderer = SDL_CreateRenderer(
        this->window, 
        -1, // screen driver index
        0 // no flags
    );

    std::cout << " init of Pseudo3DGame" << std::endl;
    this->player = std::make_unique<Player>();
    this->player->x = 4; // 4, -1, 0, 0, 0.66
    this->player->y = 4;
    this->player->dirX = -1;
    this->player->dirY = 0;
    this->player->planeX = 0;
    this->player->planeY = 0.66;

}

void Pseudo3DGame::destroy() {
    std::cout << "Game destroy" << std::endl;
}

void Pseudo3DGame::load_textures() {
    // TODO: add more textures to the game
    const char* texture_directions[] = {"assets/images/3d/TECH_1E.PNG", "assets/images/3d/TECH_2F.PNG"};

    for (const char* file : texture_directions) {
        // create a surface from the image
        SDL_Surface* surface = IMG_Load(file);
        if (!surface) {
            std::cout << "Failed to load texture image: " << file << std::endl;
            continue;
        }

        // create a texture from the surface
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            std::cout << "Failed to create texture from surface: " << file << std::endl;
        } else {
            // add the texture to the vector of textures
            textures.push_back(texture);
        }
        // surface is no longer needed
        SDL_FreeSurface(surface);
    }
}

/**
 * @brief Processes user input events.
 */
void  Pseudo3DGame::processInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        if(event.type == SDL_QUIT) {
            isRunning = false;
        } else if(event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {

                // going up, just walking straight, update position of the player
                case SDLK_UP:
                case SDLK_w: {
                    // Calculate intended position
                    double intendedX = player->x + player->dirX * movement_speed;
                    double intendedY = player->y + player->dirY * movement_speed;

                    // Check for collision
                    if (!checkCollision(intendedX, intendedY)) {
                        player->x = intendedX;
                        player->y = intendedY;
                    }
                    break;
                }

                // same as before, but walking backward
                case SDLK_DOWN: 
                case SDLK_s: {
                    double intendedX = player->x - player->dirX * 0.1;
                    double intendedY =  player->y - player->dirY * 0.1;
                    // Check for collision
                    if (!checkCollision(intendedX, intendedY)) {
                        player->x = intendedX;
                        player->y = intendedY;
                    }
                    break;
                }

                // more interesting case where we need some basic trigonometry (after searching looks like in english this is called a rotation matrix)
                // to calculate the rotation, we have vector (dirX, dirY) of the player and use the  formula :
                // V' = (x * cos(A) - y * sin(A), x * sin(A) + y * cos(A))
                // the A angle is in radian because obviously it is
                case SDLK_LEFT:
                case SDLK_a: {
                    double oldDirX = player->dirX;
                    player->dirX = player->dirX * cos(0.1) - player->dirY * sin(0.1);
                    player->dirY = oldDirX * sin(0.1) + player->dirY * cos(0.1);
                    double oldPlaneX = player->planeX;
                    player->planeX = player->planeX * cos(0.1) - player->planeY * sin(0.1);
                    player->planeY = oldPlaneX * sin(0.1) + player->planeY * cos(0.1);
                    break;
                }
                case SDLK_RIGHT:
                case SDLK_d: {
                    double oldDirX = player->dirX;
                    player->dirX = player->dirX * cos(-0.1) - player->dirY * sin(-0.1);
                    player->dirY = oldDirX * sin(-0.1) + player->dirY * cos(-0.1);
                    double oldPlaneX = player->planeX;
                    player->planeX = player->planeX * cos(-0.1) - player->planeY * sin(-0.1);
                    player->planeY = oldPlaneX * sin(-0.1) + player->planeY * cos(-0.1);
                    break;
                }
                case SDLK_ESCAPE:
                {
                    isRunning = false;
                }
                default: {
                    // Handle unhandled events
                    break;
                }
            }
        }
    }
}

/**
 * @brief Updates the game state.
 */
void  Pseudo3DGame::update() {
    int time_to_wait = MILLISECS_PER_FRAME - (SDL_GetTicks() - this->mPreviousFrame);

    if (time_to_wait > 0 && time_to_wait <= MILLISECS_PER_FRAME) {
        SDL_Delay(time_to_wait);
    }

    // calculate the time between frames
    double deltaTime = (SDL_GetTicks() - this->mPreviousFrame) / 1000.0;

    this->mPreviousFrame = SDL_GetTicks();
}

/**
 * @brief Renders the game state to the screen.
 */
void  Pseudo3DGame::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    raycasting();
    SDL_RenderPresent(renderer);
}

int Pseudo3DGame::run() {
    std::cout << "main loop running" << std::endl;
    while(isRunning) {

        processInput();
        update();
        render();       
    }

    return 0;
}

/**
 * @brief 
 */
void  Pseudo3DGame::setup() {
    
}


Pseudo3DGame& Pseudo3DGame::get_instance() {
    static Pseudo3DGame game;
    return game;
}


void Pseudo3DGame::drawVerticalLine(int start_point_X, int start_point_Y, int end_point_Y, uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    // Draw a vertical line
    // as it is a vertical line, the x coordinate is the same for both points
    SDL_RenderDrawLine(renderer, start_point_X, start_point_Y, start_point_X, end_point_Y);
}

void Pseudo3DGame::raycasting() {
    // loop through each vertical line of pixel of the game screen
    for(int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate ray position and direction
        // cameraX is the horizontal position of the current ray on the window
        double cameraX = 2 * x / double(SCREEN_WIDTH) - 1;
        double rayDirX = player->dirX + player->planeX * cameraX;
        double rayDirY = player->dirY + player->planeY * cameraX;

        // Which box of the map we're in, used to calcualte the distance to the walls
        // which is usedto calcualte the height of the wall an position on the screen
        int mapX = int(player->x);
        int mapY = int(player->y);
    
        // Length of ray from current position to next x or y-side
        double sideDistX, sideDistY;

        // Length of ray from one x or y-side to next x or y-side
        double deltaDistX = std::abs(1 / rayDirX);
        double deltaDistY = std::abs(1 / rayDirY);
        double perpWallDist;

        // What direction to step in x or y-direction (either +1 or -1)
        int stepX, stepY;

        int hit = 0; // Was there a wall hit?
        int side; // Was a NS or a EW wall hit?

        // Calculate step and initial sideDist
        if(rayDirX < 0) {
            stepX = -1;
            sideDistX = (player->x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->x) * deltaDistX;
        }
        if(rayDirY < 0) {
            stepY = -1;
            sideDistY = (player->y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->y) * deltaDistY;
        }

        // Perform DDA (Analyseur différentiel numérique)
        // this is core of the raycasting algorithm because it is the one that calculates the distance to the walls
        // and therefore the height of the wall and the position on the screen
        while(hit == 0) {
            // Jump to next map square, OR in x-direction, OR in y-direction
            if(sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Check if ray has hit a wall
            if(worldMap[mapX][mapY] > 0) hit = 1;
        }

        // Calculate distance projected on camera direction
        if(side == 0) {
            perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
        } else {
            perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;
        }

        // Calculate height of line to draw on screen
        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if(drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        // Choose wall color
        uint8_t r, g, b;
        switch(worldMap[mapX][mapY]) {
            case 1:  r = 125; g = 225; b = 200; break; // walls
            default: r = 255; g = 255; b = 255; break;
        }

        // Give x and y sides different brightness
        if(side == 1) { r /= 2; g /= 2; b /= 2; }
        
        // Draw the pixels of the stripe as a vertical line
        drawVerticalLine(x, drawStart, drawEnd, r, g, b);
    }
}

bool Pseudo3DGame::checkCollision(double x, double y) {
    // Check if the intended position is within a wall
    // used when updating position givnn by user input
    int mapX = int(x);
    int mapY = int(y);
    if (worldMap[mapX][mapY] > 0) {
        return true; // Collision detected
    }

    return false; // No collision
}
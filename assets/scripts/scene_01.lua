
scene = {
    -- sprites table
    sprites = {
        [0] = 
        {asset_id = "enemy_alan", file_path = "./assets/images/enemy_alan.png"},
        {asset_id = "player_ship", file_path = "./assets/images/player_ship.png"},
    },

    -- font table
    fonts = {
        [0] = 
        {font_id = "font_0", file_path = "./assets/fonts/highway_gothic.ttf", font_size = 32},
    },
    
    -- actions and keys table
    keys = {
        [0] =
        {name = "up", key = 119}, -- SDLK_w
        {name = "left", key = 97}, -- SDLK_a
        {name = "down", key = 115}, -- SDLK_s
        {name = "right", key = 100}, -- SDLK_d
    },

    -- actions and mouse button table
    buttons = {
        [0] =
        {name = "mouse_left_button", button_code = 1}, -- SDL_BUTTON_LEFT
    },

    -- entities table
    entities = {
        [0] =
        -- player
        {
            components = {
                -- animation = {

                -- },
                circular_collider = {
                    radius = 8,
                    width = 16,
                    height = 16
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                script = {
                    path = "./assets/scripts/player.lua"
                },
                sprite = {
                    asset_id = "player_ship",
                    width = 16,
                    height = 16,
                    src_rect = {x = 16, y = 0},
                },
                transform = {
                    position = { x = 400, y = 300},
                    scale = { x = 2.0, y =2.0},
                    rotation = 0.0
                }


            }
        },
        {
            -- enemy
            components = {
                animation = {
                    num_frames = 6,
                    frame_speed_rate = 5,
                    is_loop = true
                },
                circular_collider = {
                    radius = 8,
                    width = 16,
                    height = 16
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "enemy_alan",
                    width = 16,
                    height = 16,
                    src_rect = {x = 16, y = 0},
                },
                transform = {
                    position = { x = 200, y = 200},
                    scale = { x = 2.0, y =2.0},
                    rotation = 0.0
                }
            }
        },
        {
            components = {
                clickable = {
                },
                text = {
                    text = "Score: 100",
                    font_id = "font_0",
                    r = 150,
                    g = 10,
                    b = 150,
                    a = 255
                },
                transform = {
                    position = { x = 500, y = 50},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },


            }
        }
    }

    -- music and sound effect table
}
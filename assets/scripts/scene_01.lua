scene = {
    -- sprites table
    sprites = {
        [0] = 
        {asset_id = "background", file_path = "./assets/images/background_0.png"},
        {asset_id = "terrain", file_path = "./assets/images/terrain.png"},
        {asset_id = "player_ship", file_path = "./assets/images/admiral_ship_sprite_sheet.png"},

    },

    -- sounds table
    sounds = {
        [0] =
        {sound_id = "other_sound",file_path ="./assets/sounds/lazer.mp3"},
    },

    -- music table
    music = {
        [0] =
        {music_id = "menu_music",file_path ="./assets/sounds/GAL_v1.mp3"},
    },

    -- font table
    fonts = {
        [0] = 
        {font_id = "font_0", file_path = "./assets/fonts/highway_gothic.ttf", font_size = 32},
        {font_id = "arcade_classic_font", file_path = "./assets/fonts/prstart.ttf", font_size = 32},
        {font_id = "arcade_classic_large", file_path = "./assets/fonts/prstart.ttf", font_size = 48},
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

    -- map table
    maps = {
        width = 3000,
        height = 3000,
        map_path = "./assets/maps/level_01.tmx",
        tile_path = "./assets/maps/terrain.tsx",
        tile_name = "terrain",
    },

    -- entities table
    entities = {
        [0] =
        -- -- Background
        -- {
        --     components = {
        --         sprite = {
        --             asset_id = "background",
        --             width = 3000,
        --             height = 3000,
        --             src_rect = {x = 0, y = 0},
        --         },
        --         transform = {
        --             position = { x = 0, y = 0},
        --             scale = { x = 1.0, y = 1.0},
        --             rotation = 0.0
        --         },
        --     }
        -- },

        -- player
        {
            components = {
                animation = {
                    num_frames = 3,
                    frame_speed_rate = 5,
                    is_loop = true
                },
                camera_follow = {},
                tag = {
                    tag = "player",
                },
                box_collider = {
                    width = 32*2,
                    height = 32*2,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                script = {
                    path = "./assets/scripts/player.lua"
                },
                sprite = {
                    asset_id = "player_ship",
                    width = 32,
                    height = 32,
                    src_rect = {x = 16, y = 0},
                },
                transform = {
                    position = { x = 100, y = 100},
                    scale = { x = 2.0, y =2.0},
                    rotation = 0.0
                },
                player_velocity = {
                    player_velocity = 150
                }
            }
        },
    }
}
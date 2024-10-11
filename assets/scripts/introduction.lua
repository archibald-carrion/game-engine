
scene = {
    -- sprites table
    sprites = {
        [0] = 
        {asset_id = "background", file_path = "./assets/images/space_background_0.png"},
    },

    -- font table
    fonts = {
        [0] = 
        {font_id = "font_0", file_path = "./assets/fonts/highway_gothic.ttf", font_size = 32},
        {font_id = "arcade_classic_font", file_path = "./assets/fonts/ARCADECLASSIC.TTF", font_size = 32},

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
        -- Background
        {
            components = {
                sprite = {
                    asset_id = "background",
                    width = 2000,
                    height = 2000,
                    src_rect = {x = 0, y = 0},
                },
                transform = {
                    position = { x = 0, y = 0},
                    scale = { x = 1.0, y =1.0},
                    rotation = 0.0
                },
            }
        },
        -- button to continue
        {
            components = {
                clickable = {
                },
                script = {
                    path = "./assets/scripts/goto_level_1.lua",
                    -- path = "./assets/scripts/goto_introduction.lua",
                },
                text = {
                    text = "click here to continue",
                    font_id = "arcade_classic_font",
                    r = 150,
                    g = 10,
                    b = 50,
                    a = 255
                },
                transform = {
                    position = { x = 300, y = 200},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },


            },
        },
    }

    -- music and sound effect table
}

scene = {
    -- sprites table
    sprites = {
        -- add button sprite and other drawing to the main menu
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
        -- title
        {
            components = {
                clickable = {
                },
                text = {
                    text = "Galaxian",
                    font_id = "font_0",
                    r = 150,
                    g = 10,
                    b = 50,
                    a = 255
                },
                transform = {
                    position = { x = 300, y = 50},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },


            }
        },
        -- level 01
        {
            components = {
                clickable = {
                },
                script = {
                    path = "./assets/scripts/menu_button_01.lua",
                },
                text = {
                    text = "Level 01",
                    font_id = "font_0",
                    r = 50,
                    g = 100,
                    b = 10,
                    a = 255
                },
                transform = {
                    position = { x = 300, y = 100},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },


            },
        },
        -- level 02
        {
            components = {
                clickable = {
                },
                text = {
                    text = "Level 02",
                    font_id = "font_0",
                    r = 50,
                    g = 100,
                    b = 10,
                    a = 255
                },
                transform = {
                    position = { x = 300, y = 150},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        -- level 03
        {
            components = {
                clickable = {
                },
                text = {
                    text = "Level 03",
                    font_id = "font_0",
                    r = 50,
                    g = 100,
                    b = 10,
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
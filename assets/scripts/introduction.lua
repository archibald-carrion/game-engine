
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
        {font_id = "press_start", file_path = "./assets/fonts/prstart.ttf", font_size = 16},
        {font_id = "press_start_32", file_path = "./assets/fonts/prstart.ttf", font_size = 32},



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
        -- First paragraph
        {
            components = {
                text = {
                    text = "In the forgotten corners of the galaxy, where stars burn cold",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 100},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        {
            components = {
                text = {
                    text = "and empires crumble into dust, humanity drifts, lost among",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 130},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        {
            components = {
                text = {
                    text = "the endless void. After thousands of years of aimless",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 160},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        {
            components = {
                text = {
                    text = "exploration, mankind stands divided like never before.",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 190},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        -- Second paragraph
        {
            components = {
                text = {
                    text = "But legends speak of ancient technology, relics from an",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 250},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        {
            components = {
                text = {
                    text = "age when humans still knew where they came from. One such",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 280},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        {
            components = {
                text = {
                    text = "artifact has been found, and with it, a spark of hope.",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 310},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        -- Third paragraph
        {
            components = {
                text = {
                    text = "The stars beckon, but the answers lie somewhere in the",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 370},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        {
            components = {
                text = {
                    text = "dark, on the long-lost path...",
                    font_id = "press_start",
                    r = 255, g = 255, b = 255, a = 255
                },
                transform = {
                    position = { x = 200, y = 400},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        -- Title
        {
            components = {
                text = {
                    text = "De    Astra    Ad    Terra",
                    font_id = "press_start",
                    r = 255, g = 215, b = 0, a = 255  -- Golden color
                },
                transform = {
                    position = { x = 340, y = 480},
                    scale = { x = 1.5, y = 1.5},  -- Larger scale for the title
                    rotation = 0.0
                },
            },
        },
        -- button to continue
        {
            components = {
                clickable = {
                },
                script = {
                    path = "./assets/scripts/goto_level_1.lua",
                },
                text = {
                    text = "[click here to continue]",
                    font_id = "press_start_32",
                    r = 150,
                    g = 10,
                    b = 50,
                    a = 255
                },
                transform = {
                    position = { x = 400, y = 600},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
    }

    -- music and sound effect table
}
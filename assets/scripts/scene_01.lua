
scene = {
    -- sprites table
    sprites = {
        [0] = 
        {asset_id = "enemy_alan", file_path = "./assets/images/enemy_alan.png"},
        {asset_id = "player_ship", file_path = "./assets/images/admiral_ship_sprite_sheet.png"},
        {asset_id = "background", file_path = "./assets/images/space_background_0.png"},
        {asset_id = "barrier", file_path = "./assets/images/barrier.png"},
        {asset_id = "meteor_0", file_path = "./assets/images/meteor_0.png"},
        {asset_id = "orange_portal", file_path = "./assets/images/orange_portal.png"},
    },

    -- sounds table
    sounds = {
        [0] =
        {sound_id = "lazer",file_path ="./assets/sounds/lazer.mp3"},
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
                
                -- animation = {

                -- },
                box_collider = {
                    width = 32*2, -- scale by 2
                    height = 32*2,
                    offset = {x = 0, y= 0},
                },
                -- circular_collider = {
                --     radius = 8,
                --     width = 16,
                --     height = 16
                -- },
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
                    position = { x = 400, y = 300},
                    scale = { x = 2.0, y =2.0},
                    rotation = 0.0
                }


            }
        },
        -- barrier 1
        {
            components = {
                box_collider = {
                    width = 16*2, -- scale by 2
                    height = 16*2,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "barrier",
                    width = 16,
                    height = 16,
                    src_rect = {x = 0, y = 0},
                },
                transform = {
                    position = { x = 600, y = 200},
                    scale = { x = 2.0, y =2.0},
                    rotation = 0.0
                },
                tag = {
                    tag = "barrier",
                }
            }
        },
        -- barrier 2
        {
            components = {
                box_collider = {
                    width = 16*2, -- scale by 2
                    height = 16*2,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "barrier",
                    width = 16,
                    height = 16,
                    src_rect = {x = 0, y = 0},
                },
                transform = {
                    position = { x = 100, y = 200},
                    scale = { x = 2.0, y =2.0},
                    rotation = 0.0
                },
                tag = {
                    tag = "barrier",
                }
            }
        },
        -- barrier 3
        {
            components = {
                box_collider = {
                    width = 64, -- scale by 2
                    height = 64,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "barrier",
                    width = 16,
                    height = 16,
                    src_rect = {x = 0, y = 0},
                },
                transform = {
                    position = { x = 300, y = 400},
                    scale = { x = 4.0, y = 4.0},
                    rotation = 0.0
                },
                tag = {
                    tag = "barrier",
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
                script = {
                    path = "./assets/scripts/enemy_alan.lua"
                },
                box_collider = {
                    width = 16*2, -- scale by 2
                    height = 16*2,
                    offset = {x = 0, y= 0},
                },
                -- circular_collider = {
                --     radius = 8,
                --     width = 16,
                --     height = 16
                -- },
                rigid_body = {
                    velocity = {x = -50, y = 0},
                },
                sprite = {
                    asset_id = "enemy_alan",
                    width = 16,
                    height = 16,
                    src_rect = {x = 16, y = 0},
                },
                tag = {
                    tag = "enemy",
                },
                transform = {
                    position = { x = 500, y = 200},
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
        },
        -- meteor
        {
            components = {
                box_collider = {
                    width =32, -- scale by 2
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 50},
                },
                script = {
                    path = "./assets/scripts/meteor.lua"
                },
                sprite = {
                    asset_id = "meteor_0",
                    width = 32,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "meteor",
                },
                transform = {
                    position = { x = 500, y = 200},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },
        -- orange portal
        {
            components = {
                animation = {
                    num_frames = 3,
                    frame_speed_rate = 5,
                    is_loop = true
                },
                box_collider = {
                    width = 64,
                    height = 64,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                script = {
                    path = "./assets/scripts/portal.lua"
                },
                sprite = {
                    asset_id = "orange_portal",
                    width = 32,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "portal",
                },
                transform = {
                    position = { x = 1000, y = 1000},
                    scale = { x = 2.0, y = 2.0},
                    rotation = 0.0
                }
            }
        },
    }

    -- music and sound effect table
}
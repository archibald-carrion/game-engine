
scene = {
    -- sprites table
    sprites = {
        [0] = 
        {asset_id = "enemy_alan", file_path = "./assets/images/enemy_alan.png"},
        {asset_id = "player_ship", file_path = "./assets/images/admiral_ship_sprite_sheet.png"},
        {asset_id = "background", file_path = "./assets/images/background_0.png"},
        {asset_id = "wall_0", file_path = "./assets/images/wall_0.png"},
        {asset_id = "wall_1", file_path = "./assets/images/wall_1.png"},
        {asset_id = "meteor_0", file_path = "./assets/images/meteor_0.png"},
        {asset_id = "orange_portal", file_path = "./assets/images/orange_portal.png"},
        {asset_id = "bullet", file_path = "./assets/images/bullet_more_visible.png"},
    },

    -- sounds table
    sounds = {
        [0] =
        {sound_id = "lazer",file_path ="./assets/sounds/lazer.mp3"},
    },

    -- music table
    music = {
        [0] =
        {music_id = "menu_music", file_path ="./assets/sounds/GAL_v1.mp3"},
        {music_id = "first_level_music", file_path ="./assets/sounds/HBS.mp3"},
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
                    width = 3000,
                    height = 3000,
                    src_rect = {x = 0, y = 0},
                },
                transform = {
                    position = { x = 0, y = 0},
                    scale = { x = 1.5, y = 1.5},
                    rotation = 0.0
                },
            }
        },

        -- bullet
        {
            components = {
                box_collider = {
                    width = 8,
                    height = 8,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                script = {
                    path = "./assets/scripts/bullet.lua"
                },
                sprite = {
                    asset_id = "bullet",
                    width = 8,
                    height = 8,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "bullet",
                },
                transform = {
                    position = { x = 100, y = 100},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
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
                }
            }
        },

        -- Score text
        {
            components = {
                clickable = {
                },
                text = {
                    text = "Score: 100",
                    font_id = "font_0",
                    r = 150,
                    g = 10,
                    b = 10,
                    a = 255
                },
                transform = {
                    position = { x = 1000, y = 50},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            }
        },

        -- enemy_alan 1
        {
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
                    width = 32,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
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
                    position = { x = 700, y = 750},
                    scale = { x = 2.0, y = 2.0},
                    rotation = 0.0
                }
            }
        },

        -- enemy_alan 2
        {
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
                    width = 32,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
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
                    position = { x = 2200, y = 700},
                    scale = { x = 2.0, y = 2.0},
                    rotation = 0.0
                }
            }
        },

        -- meteor 1
        {
            components = {
                box_collider = {
                    width = 32,
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
                    position = { x = 1200, y = 1200},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        -- meteor 2
        {
            components = {
                box_collider = {
                    width = 32,
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
                    position = { x = 1800, y = 1800},
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
                    position = { x = 1500, y = 1500},
                    scale = { x = 2.0, y = 2.0},
                    rotation = 0.0
                }
            }
        },



    -- WALLS

    -- labyrinth walls
        -- vertical walls 1
        {
            components = {
                box_collider = {
                    width = 32,
                    height = 500,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 500,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 200, y = 0},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        
        {
            components = {
                box_collider = {
                    width = 500,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 500,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 200, y = 500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 300,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 300,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 200, y = 700},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 300,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 300,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 700, y = 700},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 250,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 250,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 700, y = 700},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 250,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 250,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 700, y = 700},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 700,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 700,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 0, y = 900},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 700,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 700,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1300, y = 900},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 500,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 500,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2000, y = 0},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                }
            }
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 500,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 500,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2700, y = 0},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 500,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 500,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1400, y = 1300},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 700,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 700,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1200, y = 1300},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1000, y = 300},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 800, y = 150},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 16,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 16,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 900, y = 150},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 200,
                    height = 16,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 200,
                    height = 16,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2000, y = 150},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 600, y = 1500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 200,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 200,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2500, y = 1000},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 200,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 200,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 2000},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },


        {
            components = {
                box_collider = {
                    width = 32,
                    height = 200,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 200,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 700, y = 1100},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 200,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 200,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 700, y = 1100},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 200,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 200,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 200,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 200,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 600},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2000, y = 2700},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 200,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 200,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2000, y = 1500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 100,
                    height = 100,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 100,
                    height = 100,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1000, y = 1500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 500, y = 500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 100,
                    height = 100,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 100,
                    height = 100,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 100, y = 1500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 200,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 200,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 200, y = 2500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 500, y = 2700},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 500, y = 500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1500, y = 500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 400,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 400,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 400,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 400,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 1750},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 1750},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 1750},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1500, y = 1750},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1700, y = 1500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2200, y = 1900},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 200,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 200,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1600, y = 2300},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 400,
                    height = 32,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 400,
                    height = 32,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 2500, y = 2400},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1300, y = 2500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1300, y = 500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 1700, y = 800},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 300, y = 2500},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 300, y = 2000},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },
        {
            components = {
                box_collider = {
                    width = 32,
                    height = 300,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 32,
                    height = 300,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 700, y = 2800},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        -- boxes, squared walls that looks cool, and allow to have more "blockage" against the bullet

        {
            components = {
                box_collider = {
                    width = 64,
                    height = 64,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 64,
                    height = 64,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 800, y = 300},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 64,
                    height = 64,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 64,
                    height = 64,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 300, y = 300},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },

        {
            components = {
                box_collider = {
                    width = 132,
                    height = 132,
                    offset = {x = 0, y= 0},
                },
                rigid_body = {
                    velocity = {x = 0, y = 0},
                },
                sprite = {
                    asset_id = "wall_1",
                    width = 132,
                    height = 132,
                    src_rect = {x = 0, y = 0},
                },
                tag = {
                    tag = "wall_1",
                },
                transform = {
                    position = { x = 200, y = 1200},
                    scale = { x = 1.0, y = 1.0},
                    rotation = 0.0
                },
            },
        },


    -- "invisible walls" to keep player in bounds
    
    -- large upper wall
    {
        components = {
            box_collider = {
                width = 3000,
                height = 32,
                offset = {x = 0, y= 0},
            },
            rigid_body = {
                velocity = {x = 0, y = 0},
            },
            sprite = {
                asset_id = "wall_0",
                width = 3000,
                height = 32,
                src_rect = {x = 0, y = 0},
            },
            tag = {
                tag = "wall_0",
            },
            transform = {
                position = { x = 0, y = -30},
                scale = { x = 1.0, y = 1.0},
                rotation = 0.0
            }
        }
    },
   
    -- large lower wall
    {
        components = {
            box_collider = {
                width = 3000,
                height = 32,
                offset = {x = 0, y= 0},
            },
            rigid_body = {
                velocity = {x = 0, y = 0},
            },
            sprite = {
                asset_id = "wall_0",
                width = 3000,
                height = 32,
                src_rect = {x = 0, y = 0},
            },
            tag = {
                tag = "wall_0",
            },
            transform = {
                position = { x = 0, y = 2715},
                scale = { x = 1.0, y = 1.0},
                rotation = 0.0
            }
        }
    },

    -- large left wall
    {
        components = {
            box_collider = {
                width = 32,
                height = 3000,
                offset = {x = 0, y= 0},
            },
            rigid_body = {
                velocity = {x = 0, y = 0},
            },
            sprite = {
                asset_id = "wall_0",
                width = 32,
                height = 3000,
                src_rect = {x = 0, y = 0},
            },
            tag = {
                tag = "wall_0",
            },
            transform = {
                position = { x = -30, y = 0},
                scale = { x = 1.0, y = 1.0},
                rotation = 0.0
            }
        }
    },

    -- large right wall
    {
        components = {
            box_collider = {
                width = 32,
                height = 3000,
                offset = {x = 0, y= 0},
            },
            rigid_body = {
                velocity = {x = 0, y = 0},
            },
            sprite = {
                asset_id = "wall_0",
                width = 32,
                height = 3000,
                src_rect = {x = 0, y = 0},
            },
            tag = {
                tag = "wall_0",
            },
            transform = {
                position = { x = 3000, y = 0},
                scale = { x = 1.0, y = 1.0},
                rotation = 0.0
            }
        }
    },
}
}

-- function initialize()
--     print("[LUA] Scene 01 initialized")


    
-- end
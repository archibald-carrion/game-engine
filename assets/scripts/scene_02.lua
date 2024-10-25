
scene = {
    -- sprites table
    sprites = {
        [0] = 
        {asset_id = "enemy_spider_small", file_path = "./assets/images/enemy_spider_small.png"},
        {asset_id = "enemy_circle", file_path = "./assets/images/enemy_circle_thing.png"},
        {asset_id = "player_ship", file_path = "./assets/images/admiral_ship_sprite_sheet.png"},
        {asset_id = "background", file_path = "./assets/images/background_0.png"},
        {asset_id = "wall_0", file_path = "./assets/images/wall_0.png"},
        {asset_id = "wall_1", file_path = "./assets/images/wall_1.png"},
        {asset_id = "meteor_0", file_path = "./assets/images/meteor_0.png"},
        {asset_id = "orange_portal", file_path = "./assets/images/orange_portal.png"},
        {asset_id = "bullet", file_path = "./assets/images/bullet_more_visible.png"},
        {asset_id = "speed_boost", file_path = "./assets/images/speed_boost.png"},
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
                },
                player_score = {
                    player_score = 0
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
                    position = { x = 1500, y = 1500},
                    scale = { x = 2.0, y =2.0},
                    rotation = 0.0
                },
                player_velocity = {
                    player_velocity = 150
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
                    position = { x = 2850, y = 1500},
                    scale = { x = 2.0, y = 2.0},
                    rotation = 0.0
                }
            }
        },


        -- WALLS
            -- third line of walls 
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
                                position = { x = 250, y = -200},
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
                                position = { x = 250, y = 500},
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
                                position = { x = 250, y = 1200},
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
                                position = { x = 250, y = 1900},
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
                                position = { x = 250, y = 2800},
                                scale = { x = 1.0, y = 1.0},
                                rotation = 0.0
                            }
                        }
                    },
            -- second line of walls
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
                                position = { x = 500, y = 0},
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
                                position = { x = 500, y = 700},
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
                                position = { x = 500, y = 1400},
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
                                position = { x = 500, y = 2100},
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
                                position = { x = 500, y = 3000},
                                scale = { x = 1.0, y = 1.0},
                                rotation = 0.0
                            }
                        }
                    },

            -- third line of walls 
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
                            position = { x = 750, y = -200},
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
                            position = { x = 750, y = 500},
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
                            position = { x = 750, y = 1200},
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
                            position = { x = 750, y = 1900},
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
                            position = { x = 750, y = 2800},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

            -- fourth line of walls 
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
                            position = { x = 1000, y = 0},
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
                            position = { x = 1000, y = 700},
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
                            position = { x = 1000, y = 1400},
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
                            position = { x = 1000, y = 2100},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

            -- fifth line of walls 
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
                            position = { x = 1250, y = -200},
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
                            position = { x = 1250, y = 500},
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
                            position = { x = 1250, y = 1200},
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
                            position = { x = 1250, y = 1900},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

            -- sixth line of walls 
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
                            position = { x = 1500, y = 0},
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
                            position = { x = 1500, y = 700},
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
                            position = { x = 1500, y = 1400},
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
                            position = { x = 1500, y = 2100},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

            -- seventh lineo f walls
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
                            position = { x = 1750, y = -200},
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
                            position = { x = 1750, y = 500},
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
                            position = { x = 1750, y = 1200},
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
                            position = { x = 1750, y = 1900},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

            -- 8th line of walls 
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
                            position = { x = 2000, y = 700},
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
                            position = { x = 2000, y = 1400},
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
                            position = { x = 2000, y = 2100},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

                -- fifth line of walls 
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
                            position = { x = 1250, y = -200},
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
                            position = { x = 1250, y = 500},
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
                            position = { x = 1250, y = 1200},
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
                            position = { x = 1250, y = 1900},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

           

            -- 9th lineo f walls
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
                            position = { x =  2250, y = -200},
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
                            position = { x =  2250, y = 500},
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
                            position = { x =  2250, y = 1200},
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
                            position = { x =  2250, y = 1900},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

            -- 10th line of walls 
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
                            position = { x = 2500, y = 0},
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
                            position = { x = 2500, y = 700},
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
                            position = { x = 2500, y = 1400},
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
                            position = { x = 2500, y = 2100},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
                },

            -- 11th lineo f walls
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
                            position = { x =  2750, y = -200},
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
                            position = { x =  2750, y = 500},
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
                            position = { x =  2750, y = 1200},
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
                            position = { x =  2750, y = 1900},
                            scale = { x = 1.0, y = 1.0},
                            rotation = 0.0
                        }
                    }
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



    
-- end

scene = {
    -- sprites table
    sprites = {
        [0] = 
        {asset_id = "enemy_alan", file_path = "./assets/images/enemy_alan.png"},
        {asset_id = "player_ship", file_path = "./assets/images/player_ship.png"},
    },

    -- font table
    
    -- actions and keys table
    keys = {
        [0] =
        {name = "up", key = 119}, -- SDLK_w
        {name = "left", key = 97}, -- SDLK_a
        {name = "down", key = 115}, -- SDLK_s
        {name = "right", key = 100}, -- SDLK_d
    },

    -- actions and mouse button table

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
        }
    }

    -- music and sound effect table
}
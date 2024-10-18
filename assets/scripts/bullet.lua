is_bullet_shot = false

-- function on_shot()
--     is_bullet_shot = true
--     -- get the mouse position

--     -- change the rigidbody velocity to move the bullet in


-- end

function update()
    -- get the mouse position and check if the mouse_left_button is pressed
    if not is_bullet_shot then
        -- mouse_x, mouse_y = get_mouse_position()
        is_shot_button_pressed = is_mouse_button_pressed("mouse_left_button")
    
        if is_shot_button_pressed then
            -- shoot the bullet in the direction of the rotation
            rotation = get_rotation(this)

            -- rotation 0 is point to the top of the screen

            bullet_speed = 50

            -- get the velocity of the bullet
            velocity_x = 0
            velocity_y = 0

            if rotation == 0 then
                velocity_y = -bullet_speed

            elseif rotation == 90 then
                velocity_x = bullet_speed
            
            elseif rotation == 180 then
                velocity_y = bullet_speed
            
            elseif rotation == 270 then
                velocity_x = -bullet_speed
            end

            -- check for diagonal movement
            if rotation == 45 then
                velocity_x = bullet_speed
                velocity_y = -bullet_speed
            
            elseif rotation == 135 then

                velocity_x = bullet_speed
                velocity_y = bullet_speed
            
            elseif rotation == 225 then
                velocity_x = -bullet_speed
                velocity_y = bullet_speed
            
            elseif rotation == 315 then
                velocity_x = -bullet_speed
                velocity_y = -bullet_speed
            end
            



            -- print the mouse position
            -- print("[LUA] mouse_x: " .. mouse_x .. " mouse_y: " .. mouse_y)

            -- -- Calculate the direction of the bullet
            -- local dx = mouse_x - x
            -- local dy = mouse_y - y
            -- local distance = math.sqrt(dx * dx + dy * dy)

            -- -- Normalize the direction vector to get a unit vector
            -- local direction_x = dx / distance
            -- local direction_y = dy / distance

            -- -- Calculate the velocity based on the direction and speed
            -- velocity_x = direction_x * bullet_speed
            -- velocity_y = direction_y * bullet_speed

            -- Set the velocity
            set_velocity(this, velocity_x, velocity_y)

            is_bullet_shot = true
        end
    end
end

function on_collision(other)
    other_tag = get_tag(other)

    -- if bullet shot, check if the bullet collided with a wall or enemy, then place the bullet at the player location
    if is_bullet_shot then
        -- check if the bullet collided with a wall or enemy, then place the bullet at the player location
    end

    -- if bullet not shot, just place the bullet at the player location
    if other_tag == "player" then
        if not is_bullet_shot then
            other_x, other_y = get_position(other)

            -- place the bullet at the center of the player location, which is 32x32

            other_x = other_x + 32
            other_y = other_y + 32

            set_position(this, other_x, other_y)

            -- set rotation to player rotation
            set_rotation(this, get_rotation(other))
        end
    end



end
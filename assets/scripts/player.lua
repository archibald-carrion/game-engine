-- Global variable
player_velocity = 150;

fixed_player_velocity = math.sqrt((player_velocity*player_velocity)/2)

function update()

    set_velocity(this, 0, 0);
    velocity_x = 0
    velocity_y = 0

    if is_action_activated("up") then
        velocity_y = velocity_y + -1
        -- print("[LUA] up")
    end
    if is_action_activated("left") then
        velocity_x = velocity_x + -1
        -- print("[LUA] left")
    end
    if is_action_activated("down") then
        velocity_y = velocity_y + 1
        -- print("[LUA] down")
    end
    if is_action_activated("right") then
        velocity_x = velocity_x + 1
        -- print("[LUA] right")
    end

    if velocity_x ~=0 and velocity_y ~= 0 then
        velocity_x = velocity_x * fixed_player_velocity
        velocity_y = velocity_y * fixed_player_velocity
    else
        velocity_x = velocity_x * player_velocity
        velocity_y = velocity_y * player_velocity
    end

    set_velocity(this, velocity_x, velocity_y)

    -- change the ship rotation based on the direction in which it is moving
    -- using the set_rotation(this, angle) function
    -- Calculate and set rotation based on movement direction
    if velocity_x ~= 0 or velocity_y ~= 0 then
        -- Calculate angle in radians using atan2
        local angle = math.atan2(velocity_x, -velocity_y)
        -- Convert to degrees and adjust for SDL
        local degrees = angle * (180 / math.pi)
        
        -- Set the rotation
        set_rotation(this, degrees)
    end

    
    
end

-- 
function on_collision(other)
    this_tag = get_tag(this)
    other_tag = get_tag(other)
    print("[LUA] Collision between this: "..this_tag.. " and other: "..other_tag)
end
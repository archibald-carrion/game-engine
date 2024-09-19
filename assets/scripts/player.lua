-- Global variable
player_velocity = 150;


function update()

    set_velocity(this, 0, 0);
    velocity_x = 0
    velocity_y = 0

    if is_action_activated("up") then
        velocity_y = velocity_y + -1
        print("[LUA] up")
    end
    if is_action_activated("left") then
        velocity_x = velocity_x + -1
        print("[LUA] left")
    end
    if is_action_activated("down") then
        velocity_y = velocity_y + 1
        print("[LUA] down")
    end
    if is_action_activated("right") then
        velocity_x = velocity_x + 1
        print("[LUA] right")
    end

    velocity_x = velocity_x * player_velocity
    velocity_y = velocity_y * player_velocity

    set_velocity(this, velocity_x, velocity_y)


    
    
end
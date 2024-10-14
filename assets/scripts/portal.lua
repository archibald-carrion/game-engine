
function on_collision(other)
    other_tag = get_tag(other)
    if other_tag == "player" then
        print("[LUA] Collision with player")
        -- check if player has key

        -- if player has key, teleport to next level
    end
end

function update()
    rotation = get_rotation(this)
    -- add 1 to the rotation, maybe I will change this to a random number later
    rotation = rotation + 1
    -- set the new rotation
    set_rotation(this, rotation)
end
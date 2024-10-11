
function update()
    -- apply a rotation to the meteor
    -- get the current rotation
    rotation = get_rotation(this)
    -- add 1 to the rotation, maybe I will change this to a random number later
    rotation = rotation + 1
    -- set the new rotation
    set_rotation(this, rotation)
end
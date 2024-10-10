
function on_collision(other)
    this_tag = get_tag(this)
    other_tag = get_tag(other)
    print("[LUA] Collision between this: "..this_tag.. " and other: "..other_tag)
end
#ifndef SCRIPT_COMPONENT_HPP
#define SCRIPT_COMPONENT_HPP

#include <sol/sol.hpp>

struct ScriptComponent {
    sol::function update;
    sol::function on_collision;
    sol::function on_click;
    sol::function on_init;

    ScriptComponent(sol::function  on_collision = sol::lua_nil, sol::function update= sol::lua_nil, sol::function on_click= sol::lua_nil, sol::function on_init= sol::lua_nil) {
        this->on_collision = on_collision;
        this->update = update;
        this->on_click = on_click;
        this->on_init = on_init;
    }
};


#endif // SCRIPT_COMPONENT_HPP
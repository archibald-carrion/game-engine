#ifndef SCRIPT_COMPONENT_HPP
#define SCRIPT_COMPONENT_HPP

#include <sol/sol.hpp>

struct ScriptComponent {
    sol::function update;

    ScriptComponent(sol::function update= sol::lua_nil) {
        this->update = update;
    }
};


#endif // SCRIPT_COMPONENT_HPP
#ifndef SCRIPT_SYSTEM_HPP
#define SCRIPT_SYSTEM_HPP

#include <sol/sol.hpp>
#include <memory>

#include "../binding/lua_binding.hpp"
#include "../components/script_component.hpp"
#include "../ECS/ECS.hpp"

class ScriptSystem : public System {
public:
    ScriptSystem() {
        RequireComponent<ScriptComponent>();
    }

    void create_lua_binding(sol::state& lua) {
        // classes
        lua.new_usertype<Entity>("entity");

        // functions
        lua.set_function("is_action_activated", is_action_activated);
        lua.set_function("set_velocity", set_velocity);
        lua.set_function("get_velocity", get_velocity);

        lua.set_function("get_tag", get_tag);
        lua.set_function("go_to_scene", go_to_scene);

        lua.set_function("get_position", get_position);
        lua.set_function("set_position", set_position);
        lua.set_function("get_size", get_size);



        lua.set_function("left_collision", left_collision);
        lua.set_function("right_collision", right_collision);


    }

    void update(sol::state& lua) {
        for (auto& entity : get_entities()) {
            const auto& script = entity.get_component<ScriptComponent>();

            if (script.update != sol::lua_nil) {
                lua["this"] = entity;
                script.update();
            }
        }
    }
};

#endif // SCRIPT_SYSTEM_HPP
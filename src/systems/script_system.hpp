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

        lua.set_function("set_rotation", set_rotation);
        lua.set_function("get_rotation", get_rotation);

        lua.set_function("get_tag", get_tag);
        lua.set_function("go_to_scene", go_to_scene);

        lua.set_function("get_position", get_position);
        lua.set_function("set_position", set_position);
        lua.set_function("get_size", get_size);

        // collision detection functions
        lua.set_function("left_collision", left_collision);
        lua.set_function("right_collision", right_collision);
        lua.set_function("top_collision", top_collision);
        lua.set_function("bottom_collision", bottom_collision);

        // Sound functions
        // lua.set_function("play_sound", play_sound);
        // lua.set_function("stop_sound", stop_sound);
        // lua.set_function("pause_sound", pause_sound);
        // lua.set_function("resume_sound", resume_sound);
        // lua.set_function("set_sound_volume", set_sound_volume);
        // lua.set_function("get_sound_volume", get_sound_volume);
        // lua.set_function("set_sound_loop", set_sound_loop);
        // lua.set_function("is_sound_looping", is_sound_looping);
        // lua.set_function("load_sound", load_sound);


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
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
        lua.set_function("is_action_activated", is_action_activated);
    }

    void update(sol::state& lua) {
        for (auto& entity : get_entities()) {
            const auto& script = entity.get_component<ScriptComponent>();

            if (script.update != sol::lua_nil) {
                script.update();
            }
        }
    }
};

#endif // SCRIPT_SYSTEM_HPP
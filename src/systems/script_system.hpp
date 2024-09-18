#ifndef SCRIPT_SYSTEM_HPP
#define SCRIPT_SYSTEM_HPP

#include <sol/sol.hpp>
#include <memory>

#include "../components/script_component.hpp"
#include "../ECS/ECS.hpp"

class ScriptSystem : public System {
public:
    ScriptSystem() {
        RequireComponent<ScriptComponent>();
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
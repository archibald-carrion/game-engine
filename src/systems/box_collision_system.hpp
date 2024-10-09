#ifndef BOX_COLLLSIION_SYSTEM_HPP
#define BOX_COLLLSIION_SYSTEM_HPP

#include "../components/box_collider_component.hpp"
#include "../components/script_component.hpp"
#include "../components/transform_component.hpp"
#include "../ECS/ECS.hpp"

#include <iostream>

class BoxCollisionSystem : public System {
private:
    bool check_AABB_collision(float a_x, float a_y, float a_w, float a_h, float b_x, float b_y, float b_w, float b_h) {
        return(
            a_x < b_x + b_w &&
            a_x + a_w > b_x &&
            a_y < b_y + b_h &&
            a_y + a_h > b_y
        );
    }

public:
    BoxCollisionSystem() {
        RequireComponent<BoxColliderComponent>();
        RequireComponent<TransformComponent>();
    }

    void update(sol::state& lua){
         auto entities = get_entities();
        for(auto i = entities.begin(); i != entities.end(); i++) {
            Entity a = *i;
            const auto& a_collider = a.get_component<BoxColliderComponent>();
            const auto& a_transform = a.get_component<TransformComponent>();

            for(auto j =i; j != entities.end(); j++) {
                Entity b = *j;

                if(a==b) {
                    continue;
                }

                const auto& b_collider = b.get_component<BoxColliderComponent>();
                const auto& b_transform = b.get_component<TransformComponent>();

                

                bool there_is_collision = check_AABB_collision(
                    a_transform.position.x,
                    a_transform.position.y,
                    static_cast<float>(a_collider.width),
                    static_cast<float>(a_collider.height),
                    b_transform.position.x,
                    b_transform.position.y,
                    static_cast<float>(b_collider.width),
                    static_cast<float>(b_collider.height)
                );

                if(there_is_collision) {
                    // std::cout << "collision" << std::endl;
                    if(a.has_component<ScriptComponent>()) {
                        const auto& script = a.get_component<ScriptComponent>();
                        if(script.on_collision != sol::nil) {
                            lua["this"] = a;
                            script.on_collision(b);
                        }

                    }

                    if(b.has_component<ScriptComponent>()) {
                        const auto& script = b.get_component<ScriptComponent>();
                        if(script.on_collision != sol::nil) {
                            lua["this"] = b;
                            script.on_collision(a);
                        }

                    }
                }
            }

        }
    
    }

};
#endif // BOX_COLLLSIION_SYSTEM_HPP
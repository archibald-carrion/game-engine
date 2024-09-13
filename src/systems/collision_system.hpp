#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include "../ECS/ECS.hpp"
#include "../components/transform_component.hpp"
#include "../components/circle_collider_component.hpp"


class CollisionSystem : public System
{
private:
    /* data */

public:
    CollisionSystem(/* args */) {
        RequireComponent<CircleColliderComponent>();
        RequireComponent<TransformComponent>();
    }

    void update() {
        auto entities = get_entities();
        for(auto i = entities.begin(); i != entities.end(); i++) {
            Entity a = *i;
            auto a_collider = a.get_component<CircleColliderComponent>();
            auto a_transform = a.get_component<TransformComponent>();

            for(auto j =i; j != entities.end(); j++) {
                Entity b = *j;

                if(a==b) {
                    continue;
                }

                auto b_collider = b.get_component<CircleColliderComponent>();
                auto b_transform = b.get_component<TransformComponent>();

                bool there_is_collision = check_circular_collision();

                if(there_is_collision) {
                    // emit event
                }
            }

        }
    }

    bool  check_circular_collision() {

    }

    ~CollisionSystem();
};


#endif // COLLISION_SYSTEM_HPP
#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include <iostream>
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

                glm::vec2 a_center_pos = glm::vec2(
                    a_transform.position.x - (a_collider.width/2)* a_transform.scale.x,
                    a_transform.position.y - (a_collider.height/2)* a_transform.scale.y
                );

                glm::vec2 b_center_pos = glm::vec2(
                    b_transform.position.x - (b_collider.width/2)* b_transform.scale.x, 
                    b_transform.position.y - (b_collider.height/2)* b_transform.scale.y
                );

                int a_radius = a_collider.radius*a_transform.scale.x;
                int b_radius = b_collider.radius*b_transform.scale.x;

                bool there_is_collision = check_circular_collision(a_radius, b_radius, a_center_pos, b_center_pos);

                if(there_is_collision) {
                    // emit event
                    std::cout << "[COLLISIONSYSTEM] collision between " << a.get_id() << " and " << b.get_id() << std::endl;
                }
            }

        }
    }

    bool  check_circular_collision(int a_radius, int b_radius, glm::vec2 a_pos, glm::vec2 b_pos) {
        glm::vec2 dif = a_pos - b_pos;
        double lenght =glm::sqrt((dif.x*dif.x)+(dif.y*dif.y));

        bool is_colliding = (a_radius+b_radius) >= lenght;

        return is_colliding;

    }

    // ~CollisionSystem();
};


#endif // COLLISION_SYSTEM_HPP
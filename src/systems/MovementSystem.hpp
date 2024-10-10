#ifndef MOVEMENTSYSTEM_HPP
#define MOVEMENTSYSTEM_HPP

#include "../ECS/ECS.hpp"
#include "../components/RigidBodyComponent.hpp"
#include "../components/transform_component.hpp"

class MovementSystem : public System {
public:
    MovementSystem() {
        RequireComponent<RigidBodyComponent>();
        RequireComponent<TransformComponent>();
    }

    void Update(double dt) {
        for(auto entity: get_entities()) {
            const auto& rigid_body = entity.get_component<RigidBodyComponent>();
            auto& transform = entity.get_component<TransformComponent>();

            transform.previous_position = transform.position;

            transform.position.x += rigid_body.velocity.x * dt;
            transform.position.y += rigid_body.velocity.y * dt;

        }
    }

};

#endif // MOVEMENTSYSTEM_HPP
#ifndef OVERLAPSYSTEM_HPP
#define OVERLAPSYSTEM_HPP

#include <memory>

#include "../components/box_collider_component.hpp"
#include "../components/RigidBodyComponent.hpp"
#include "../components/transform_component.hpp"
#include "../ECS/ECS.hpp"
#include "../event_manager/event_manager.hpp"
#include "../events/collision_event.hpp"

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class OverlapSystem : public System {
private:

    bool check_collision(Entity a, Entity b, direction dir) {
        auto& a_collider = a.get_component<BoxColliderComponent>();
        auto& a_transform = a.get_component<TransformComponent>();
        auto& b_collider = b.get_component<BoxColliderComponent>();
        auto& b_transform = b.get_component<TransformComponent>();

        float a_x = a_transform.previous_position.x;
        float a_y = a_transform.previous_position.y;
        float a_w = static_cast<float>(a_collider.width);
        float a_h = static_cast<float>(a_collider.height);

        float b_x = b_transform.previous_position.x;
        float b_y = b_transform.previous_position.y;
        float b_w = static_cast<float>(b_collider.width);
        float b_h = static_cast<float>(b_collider.height);

        // check if upper side of a is colliding with lower side of b
        if(direction::UP == dir) {
            return (
                a_x < b_x + b_w &&
                a_x + a_w > b_x &&
                a_y >b_y
            );
        } 

        // check if lower side of a is colliding with upper side of b
        if(direction::DOWN == dir) {
            return (
                a_x < b_x + b_w &&
                a_x + a_w > b_x &&
                a_y < b_y
            );
        }

        // check if left side of a is colliding with right side of b
        if(direction::LEFT == dir) {
            return (
                a_x > b_x &&
                a_y < b_y + b_h &&
                a_y + a_h > b_y
            );
        }

        // check if right side of a is colliding with left side of b
        if(direction::RIGHT == dir) {
            return (
                a_x < b_x &&
                a_y < b_y + b_h &&
                a_y + a_h > b_y
            );
        }

        return false;
    }

    void avoid_overlad(Entity a, Entity b) {
        auto& a_collider = a.get_component<BoxColliderComponent>();
        auto& a_transform = a.get_component<TransformComponent>();

        auto& b_collider = b.get_component<BoxColliderComponent>();
        auto& b_transform = b.get_component<TransformComponent>();
        auto& b_rigidbody = b.get_component<RigidBodyComponent>();

        if(check_collision(a, b, direction::UP)) {
            // move b upward
            b_transform.position = glm::vec2(b_transform.position.x, a_transform.position.y - b_collider.height);
            // change velocity of b
            b_rigidbody.velocity = glm::vec2(b_rigidbody.velocity.x, 0.0f); 
        }

        if(check_collision(a, b, direction::DOWN)) {
            // move b downward
            b_transform.position = glm::vec2(b_transform.position.x, a_transform.position.y + a_collider.height);
            // change velocity of b
            b_rigidbody.velocity = glm::vec2(b_rigidbody.velocity.x, 0.0f); 
        }

    }

public:
    OverlapSystem() {
        RequireComponent<BoxColliderComponent>();
        RequireComponent<RigidBodyComponent>();
        RequireComponent<TransformComponent>();
    }

    void SubscribeToCollisionEvent(const std::unique_ptr<EventManager>& event_manager) {
        event_manager->subscribe_to_event<CollisionEvent, OverlapSystem>(this, &OverlapSystem::OnCollisionEvent);
    }

    void OnCollisionEvent(CollisionEvent& e) {
        auto& a_rigidbody = e.a.get_component<RigidBodyComponent>();
        auto& b_rigidbody = e.b.get_component<RigidBodyComponent>();

        if (a_rigidbody.is_solid && b_rigidbody.is_solid) {
            if(a_rigidbody.mass >= b_rigidbody.mass) {
                avoid_overlad(e.a, e.b);
            } else {
                avoid_overlad(e.b, e.a);
            }
       }
   }
};
#endif
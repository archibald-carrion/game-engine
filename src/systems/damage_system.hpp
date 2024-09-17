#ifndef DAMAGE_SYSTEM_HPP
#define DAMAGE_SYSTEM_HPP

#include <memory>
#include <iostream>

#include "../ECS/ECS.hpp"
#include "../components/circle_collider_component.hpp"
#include "../event_manager/event_manager.hpp"
#include "../events/collision_event.hpp"

class DamageSystem : public System {

public:
    DamageSystem() {
        RequireComponent<CircleColliderComponent>();
    }

    void subscribe_to_collision_event(std::unique_ptr<EventManager>& event_manager) {
        event_manager->subscribe_to_event<CollisionEvent, DamageSystem>(this, &DamageSystem::on_collision);
    }

    void on_collision(CollisionEvent& e) {
        std::cout << "[DAMAGESYSTEM] collision between " << e.a.get_id() << " and " << e.b.get_id() << std::endl;
        e.a.kill();
        e.b.kill();
    }

};


#endif // DAMAGE_SYSTEM_HPP
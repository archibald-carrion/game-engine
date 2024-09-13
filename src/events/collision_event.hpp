#ifndef COLLISION_EVENT_HPP
#define COLLISION_EVENT_HPP

#include "../event_manager/event_manager.hpp"
#include "../ECS/ECS.hpp"

class CollisionEvent : public Event {
public:
    Entity a;
    Entity b;

    CollisionEvent(Entity a, Entity b): a(a), b(b) {
        
    }
};


#endif // COLLISION_EVENT_HPP
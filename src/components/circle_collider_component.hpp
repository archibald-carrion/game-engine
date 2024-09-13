#ifndef CIRCLE_COLLISION_COMPONENT_HPP
#define CIRCLE_COLLISION_COMPONENT_HPP

struct CircleColliderComponent
{
    int radius;
    CircleColliderComponent(int radius = 0) {
        this->radius = radius;
    }
};


#endif // CIRCLE_COLLISION_COMPONENT_HPP
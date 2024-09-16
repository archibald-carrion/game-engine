#ifndef CIRCLE_COLLISION_COMPONENT_HPP
#define CIRCLE_COLLISION_COMPONENT_HPP

struct CircleColliderComponent
{
    int radius;

    int width;
    int height;

    CircleColliderComponent(int radius = 0, int width=0, int height = 0) {
        this->radius = radius;
        this->width = width;
        this->height = height;
    }
};


#endif // CIRCLE_COLLISION_COMPONENT_HPP
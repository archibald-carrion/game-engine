#ifndef RIGIDBODYCOMPONENT_HPP
#define RIGIDBODYCOMPONENT_HPP

#include <glm/glm.hpp> // GLM math library, used for vec2

/**
 * @struct RigidBodyComponent
 * @brief The RigidBodyComponent struct represents a rigid body component for an entity.
 */
struct RigidBodyComponent {

    bool is_dynamic; // if the rigid body is dynamic, it will move
    bool is_solid; // if the rigid body is solid, it will collide with other solid objects

    glm::vec2 sum_forces; // sum of all forces acting on the rigid body
    glm::vec2 acceleration; // acceleration of the rigid body
    glm::vec2 velocity; // velocity of the rigid body

    float mass; // mass of the rigid body
    float inverse_mass; // inverse mass of the rigid body


    /**
     * @brief Construct a new Rigid Body Component object
     * @param is_dynamic if the rigid body is dynamic, default is false
     * @param is_solid if the rigid body is solid, default is false
     * @param mass the mass of the rigid body, default is 1
     */
    RigidBodyComponent(bool is_dynamic = false, bool is_solid = false, float mass = 1) {
        this->is_dynamic = is_dynamic;
        this->is_solid = is_solid;
        this->mass = mass;
        this->inverse_mass = 1/mass;
    }
};

#endif // RIGIDBODYCOMPONENT_HPP
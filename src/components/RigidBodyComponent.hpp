#ifndef RIGIDBODYCOMPONENT_HPP
#define RIGIDBODYCOMPONENT_HPP

#include <glm/glm.hpp> // GLM math library, used for vec2

/**
 * @struct RigidBodyComponent
 * @brief The RigidBodyComponent struct represents a rigid body component for an entity.
 */
struct RigidBodyComponent {

    bool is_dynamic;

    glm::vec2 sum_forces;
    glm::vec2 acceleration;
    glm::vec2 velocity; // velocity of the rigid body

    float mass;
    float inverse_mass;


    /**
     * @brief Construct a new Rigid Body Component object
     * @param velocity The velocity of the rigid body
     */
    RigidBodyComponent(bool is_dynamic = false, float mass = 1) {
        this->is_dynamic = is_dynamic;
        this->mass = mass;
        this->inverse_mass = 1/mass;
    }
};

#endif // RIGIDBODYCOMPONENT_HPP
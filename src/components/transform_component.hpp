#ifndef TRASNFORM_COMPONENTS_HPP
#define TRASNFORM_COMPONENTS_HPP

#include <glm/glm.hpp>

struct TransformComponent {
    glm::vec2 position;
    glm::vec2 previous_position;
    glm::vec2 scale;
    double rotation;

    TransformComponent(glm::vec2 position = glm::vec2(0.0f, 0.0f), glm::vec2 scale = glm::vec2(1.0f, 1.0f), double rotation = 0.0) {
        this->position = position;
        this->previous_position = position;
        this->scale = scale;
        this->rotation = rotation;
    }
};














#endif // TRASNFORM_COMPONENTS_HPP
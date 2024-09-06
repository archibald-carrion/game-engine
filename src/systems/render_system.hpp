#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "../components/sprite_component.hpp"
#include "../components/transform_component.hpp"
#include "../ECS/ECS.hpp"

class RenderSystem: public System {
public:
    RenderSystem() {
        RequireComponent<SpriteComponent>();
    }
};


#endif RENDER_SYSTEM_HPP
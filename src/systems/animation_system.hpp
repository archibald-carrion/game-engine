#ifndef ANIMATION_SYSTEM_HPP
#define ANIMATION_SYSTEM_HPP

#include <SDL2/SDL.h>

#include "../ECS/ECS.hpp"
#include "../components/animation_component.hpp"
#include "../components/sprite_component.hpp"

class AnimationSystem : public System {
public:
    AnimationSystem() {
        // set as 1 in the bitset
        RequireComponent<AnimationComponent>();
        RequireComponent<SpriteComponent>();
    }

    void update() {
        for (auto entity : get_entities()) {
            auto& animation = entity.get_component<AnimationComponent>();
            auto& sprite = entity.get_component<SpriteComponent>();

            animation.current_frame = ((SDL_GetTicks() -animation.start_time) 
                * animation.frame_speed_rate / 1000) % animation.num_frames;

            sprite.src_rect.x = sprite.width * animation.current_frame;
        }
    }


};



#endif // ANIMATION_SYSTEM_HPP
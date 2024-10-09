#ifndef CAMERA_MOVEMENT_SYSTEM_HPP
#define CAMERA_MOVEMENT_SYSTEM_HPP

#include "../ECS/ECS.hpp"
#include <SDL2/SDL.h>
#include "../game/game.hpp"

#include "../components/camera_follow_component.hpp"
#include "../components/transform_component.hpp"

class CameraMovementSystem : public System {
public:
    CameraMovementSystem() {
        RequireComponent<CameraFollowComponent>();
        RequireComponent<TransformComponent>();
    }

    void update(SDL_Rect& camera){
        for(auto entity: get_entities()) {
            const auto& tranform = entity.get_component<TransformComponent>();

            if(tranform.position.x + (camera.w /2) < static_cast<float>(Game::get_instance().map_width)) {
                camera.x = static_cast<int>(tranform.position.x) - (camera.w/2);
            }

            if(tranform.position.y + (camera.w /2) < static_cast<float>(Game::get_instance().map_height)) {
                camera.y = static_cast<int>(tranform.position.y) - (camera.h/2);
            }

            camera.x =camera.x < 0 ? 0:camera.x;
            camera.y =camera.y < 0 ? 0:camera.y;

        }
    }

};

#endif // CAMERA_MOVEMENT_SYSTEM_HPP
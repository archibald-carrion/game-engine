#ifndef UI_SYSTEM_HPP
#define UI_SYSTEM_HPP

#include <SDL2/SDL.h>
#include <memory>
#include <iostream>
#include <string>

#include "../ECS/ECS.hpp"
#include "../components/clickable_component.hpp"
#include "../components/text_component.hpp"
#include "../components/transform_component.hpp"

#include "../event_manager/event_manager.hpp"
#include "../events/click_event.hpp"

class UISystem : public System {
public:
    UISystem() {
        RequireComponent<ClickableComponent>();
        RequireComponent<TransformComponent>();
        RequireComponent<TextComponent>();
    }

    void suscribe_to_click_event(std::unique_ptr<EventManager>& event_manager) {
        event_manager->subscribe_to_event<ClickEvent, UISystem>(this, &UISystem::on_click);
    }

    void on_click(ClickEvent& e) {
        for(auto entity : get_entities()) {
            const auto& transform = entity.get_component<TransformComponent>();
            const auto& text = entity.get_component<TextComponent>();

             bool is_click_inside = transform.position.x < e.position_x &&
                                    e.position_x < transform.position.x + text.width &&
                                    transform.position.y < e.position_y &&
                                    e.position_y < transform.position.y + text.height;

            if (is_click_inside) {
                // TODO: execute subroutine on_click from script
                std::cout << "Entity clicked: " << entity.get_id() << std::endl;
            }
        }
    }
};


#endif // UI_SYSTEM_HPP
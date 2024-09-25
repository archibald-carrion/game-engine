#ifndef CLICK_EVENT_HPP
#define CLICK_EVENT_HPP

#include "../ECS/ECS.hpp"

#include "../event_manager/event.hpp"

class ClickEvent : public Event {
public:
    int button_code;
    int position_x;
    int position_y;

    ClickEvent(int button_code, int position_x, int position_y) {
        this->button_code = button_code;
        this->position_x = position_x;
        this->position_y = position_y;
    }
};

#endif // CLICK_EVENT_HPP
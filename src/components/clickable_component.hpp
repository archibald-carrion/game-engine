#ifndef CLICKABLE_COMPONENT_HPP
#define CLICKABLE_COMPONENT_HPP

struct ClickableComponent {
    bool is_clicked;
    bool is_hovered;

    ClickableComponent() {
        is_clicked = false;
        is_hovered = false;
    }
};



#endif // CLICKABLE_COMPONENT_HPP
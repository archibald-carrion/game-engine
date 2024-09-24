#ifndef CONTROLLER_MANAGER_HPP
#define CONTROLLER_MANAGER_HPP


#include<SDL2/SDL.h>
#include <map>
#include <tuple>
#include <string>

class ControllerManager {
private:
    std::map<std::string, int> action_key_name;
    std::map<int, bool> key_state; // key down in the video tutorial

    std::map<std::string, int> mouse_buttons_name;
    std::map<int, bool> mouse_button_state;
    
    int mouse_position_x;
    int mouse_position_y;


public:
    ControllerManager();
    ~ControllerManager();
    void clear();

    // Keyboard Controller
    void add_key(const std::string& key_name, int key_code);
    bool is_key_pressed(const std::string& key_name);

    void update_key(const std::string& key_name, bool state);
    void update_key(int key_code, bool state);

    void set_key_to_pressed(int key_code);
    void set_key_to_pressed(const std::string& key_name);

    void set_key_to_up(int key_code);
    void set_key_to_up(const std::string& key_name);

    // Mouse controller
    void add_mouse_button(const std::string button_name, int mouse_button_code);
    bool is_mouse_button_pressed(const std::string& mouse_button_name);

    void update_mouse_button(int mouse_button_code, bool state);

    void set_mouse_position(int x, int y);
    std::tuple<int, int> get_mouse_position();
    
    void set_mouse_button_to_pressed(int mouse_button_code);
    void set_mouse_button_to_up(int mouse_button_code);




};

#endif // CONTROLLER_MANAGER_HPP
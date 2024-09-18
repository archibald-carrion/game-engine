#ifndef CONTROLLER_MANAGER_HPP
#define CONTROLLER_MANAGER_HPP


#include<SDL2/SDL.h>
#include <map>
#include <string>

class ControllerManager {
private:
    std::map<std::string, int> action_key_name;
    std::map<int, bool> key_state; // key down in the video tutorial

public:
    ControllerManager();
    ~ControllerManager();

    void add_key(const std::string& key_name, int key_code);


    void update_key(const std::string& key_name, bool state);
    void update_key(int key_code, bool state);

    void set_key_to_pressed(int key_code);
    void set_key_to_pressed(const std::string& key_name);
    void set_key_to_up(int key_code);
    void set_key_to_up(const std::string& key_name);

    bool is_key_pressed(const std::string& key_name);

    void clear();


};

#endif // CONTROLLER_MANAGER_HPP
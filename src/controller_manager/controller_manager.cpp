#include "controller_manager.hpp"
#include <iostream>

ControllerManager::ControllerManager() {
    std::cout << "[CONTROLLERMANAGER] ControllerManager constructor" << std::endl;
}

ControllerManager::~ControllerManager() {
    std::cout << "[CONTROLLERMANAGER] ControllerManager destructor" << std::endl;
}

void ControllerManager::add_key(const std::string& key_name, int key_code) {
    action_key_name.emplace(key_name, key_code);
    key_state.emplace(key_code, false);

}

void ControllerManager::update_key(const std::string& key_name, bool state) {
    // update the key state
    auto it = key_state.find(action_key_name[key_name]);
    // check if the key name exists
    if (it != key_state.end()) {
        key_state[action_key_name[key_name]] = state;
    }
}

void ControllerManager::update_key(int key_code, bool state) {
    // update the key state
    auto it = key_state.find(key_code);
    // check if the key code exists
    if (it != key_state.end()) {
        key_state[key_code] = state;
    }
}

void ControllerManager::set_key_to_pressed(const std::string& key_name) {
    // no need to check if the key name exists because it was checked in the previous function
    if (!key_name.empty()) {
        update_key(key_name, true);
    }
}

void ControllerManager::set_key_to_pressed(int key_code) {
    // no need to check if the key code exists because it was checked in the previous function
    if (key_code != -1) {
        update_key(key_code, true);
    }
}

void ControllerManager::set_key_to_up(const std::string& key_name) {
    // no need to check if the key name exists because it was checked in the previous function
    if (!key_name.empty()) {
        update_key(key_name, false);
    }
}

void ControllerManager::set_key_to_up(int key_code) {
    // no need to check if the key code exists because it was checked in the previous function
    if (key_code != -1) {
        update_key(key_code, false);
    }
}

bool ControllerManager::is_key_pressed(const std::string& key_name) {
    auto it = action_key_name.find(key_name);
    // check if the key name exists
    if (it != action_key_name.end()) {
        int key_code = action_key_name[key_name];
        return key_state[key_code];
    }
    return false;
}

void ControllerManager::clear() {
    action_key_name.clear();
    key_state.clear();
}
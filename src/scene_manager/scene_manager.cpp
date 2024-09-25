#include "scene_manager.hpp"
#include <iostream>

SceneManager::SceneManager() {
    std::cout << "[SCENEMANAGER] Constructor" << std::endl;
    this->scene_loader = std::make_unique<SceneLoader>();
}

SceneManager::~SceneManager() {
    scene_loader.reset();
    std::cout << "[SCENEMANAGER] Destructor" << std::endl;
}

void SceneManager::load_scene_from_script(const std::string& scene_path, sol::state& lua) {
    
}

void SceneManager::load_scene() {

}

std::string SceneManager::get_next_scene() const{

}

void SceneManager::set_next_scene(const std::string& next_scene) {
    this->next_scene = next_scene;
}

bool SceneManager::is_current_scene_running() const {
    return this->is_scene_running;
}
    
void SceneManager::start_scene() {
    this->is_scene_running = true;
}
    
void SceneManager::stop_scene() {
    this->is_scene_running = false;
}
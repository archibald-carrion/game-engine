#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <map>
#include<map>
#include <sol/sol.hpp>
#include <string>


#include "scene_loader.hpp"

class SceneManager {
private:
    std::map<std::string, std::string> scenes;
    std::string next_scene;
    bool is_scene_running = false;
    std::unique_ptr<SceneLoader> scene_loader;

public:
    SceneManager();
    ~SceneManager();
    void load_scene_from_script(const std::string& scene_path, sol::state& lua);
    void load_scene();

    std::string get_next_scene() const;
    void set_next_scene(const std::string& next_scene);

    bool is_current_scene_running() const;
    void start_scene();
    void stop_scene();

};

#endif // SCENE_MANAGER_HPP
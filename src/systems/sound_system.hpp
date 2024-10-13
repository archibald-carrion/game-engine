#ifndef SOUND_SYSTEM_HPP
#define SOUND_SYSTEM_HPP

#include <iostream>
#include <sol/sol.hpp>
#include "../systems/script_system.hpp"

// #include "../assets_manager/assets_manager.hpp"
// #include "../components/sound_component.hpp"
#include "../ECS/ECS.hpp"

class SoundSystem : public System {
public:
    SoundSystem() {
        std::cout << "[SOUNDSYSTEM] Constructor" << std::endl;
        // RequireComponent<SoundComponent>();
    }

    void init_audio_from_script(sol::state& lua, std::unique_ptr<Registry>& registry) {
        for (auto& entity : get_entities()) {
            const auto& script = entity.get_component<ScriptComponent>();

            if (script.on_init != sol::lua_nil) {
                lua["this"] = entity;
                script.on_init();
            }
        }
    }

    // void update(const std::unique_ptr<AssetsManager>& asset_manager) {
    //     for (auto entity : get_entities()) {
    //         auto& sound = entity.get_component<SoundComponent>();

    //         // Load the sound if it hasn't been loaded yet
    //         if (!sound.sound) {
    //             sound.sound = asset_manager->get_sound(sound.sound_id);
    //             if (!sound.sound) {
    //                 std::cerr << "Failed to load sound: " << sound.sound_id << std::endl;
    //                 continue;
    //             }
    //         }

    //         // Set the volume for the sound
    //         Mix_VolumeChunk(sound.sound, sound.volume);
    //     }
    // }

    // void play_sound(Entity entity) {
    //     if (entity.has_component<SoundComponent>()) {
    //         auto& sound = entity.get_component<SoundComponent>();
    //         if (sound.sound) {
    //             int loops = sound.is_looping ? -1 : 0;
    //             sound.channel = Mix_PlayChannel(sound.channel, sound.sound, loops);
    //             if (sound.channel == -1) {
    //                 std::cerr << "Failed to play sound: " << Mix_GetError() << std::endl;
    //             }
    //         }
    //     }
    // }

    // void stop_sound(Entity entity) {
    //     if (entity.has_component<SoundComponent>()) {
    //         auto& sound = entity.get_component<SoundComponent>();
    //         if (sound.channel != -1) {
    //             Mix_HaltChannel(sound.channel);
    //             sound.channel = -1;
    //         }
    //     }
    // }

    // void pause_sound(Entity entity) {
    //     if (entity.has_component<SoundComponent>()) {
    //         auto& sound = entity.get_component<SoundComponent>();
    //         if (sound.channel != -1) {
    //             Mix_Pause(sound.channel);
    //         }
    //     }
    // }

    // void resume_sound(Entity entity) {
    //     if (entity.has_component<SoundComponent>()) {
    //         auto& sound = entity.get_component<SoundComponent>();
    //         if (sound.channel != -1) {
    //             Mix_Resume(sound.channel);
    //         }
    //     }
    // }
};

#endif // SOUND_SYSTEM_HPP
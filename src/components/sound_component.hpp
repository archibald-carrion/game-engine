#ifndef SOUND_COMPONENT_HPP
#define SOUND_COMPONENT_HPP

#include <SDL2/SDL_mixer.h>
#include <string>

struct SoundComponent {
    std::string sound_id;
    Mix_Chunk* sound;
    int volume;
    int channel;
    bool is_looping;

    SoundComponent(const std::string& sound_id = "none", int volume = MIX_MAX_VOLUME, int channel = -1, bool is_looping = false) {
        this->sound_id = sound_id;
        this->volume = volume;
        this->channel = channel;
        this->is_looping = is_looping;
        this->sound = nullptr;
    }

    ~SoundComponent() {
        if (sound) {
            Mix_FreeChunk(sound);
        }
    }
};

#endif // SOUND_COMPONENT_HPP
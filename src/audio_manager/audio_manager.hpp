#ifndef AUDIO_MANAGER_HPP
#define AUDIO_MANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <map>
#include <string>

class AudioManager {
private:
    std::map<std::string, Mix_Music*> music_tracks;   // For music (streamed)
    std::map<std::string, Mix_Chunk*> sound_effects;  // For short sound effects (pre-loaded)

public:
    AudioManager();
    ~AudioManager();

    // Load and manage music
    void add_music(const std::string& music_id, const std::string& file_path);
    Mix_Music* get_music(const std::string& music_id);

    // Load and manage sound effects
    void add_sound_effect(const std::string& sound_id, const std::string& file_path);
    Mix_Chunk* get_sound_effect(const std::string& sound_id);

    // Play music and sound effects
    void play_music(const std::string& music_id, int loops = -1); // -1 for infinite loops
    void play_sound_effect(const std::string& sound_id, int loops = 0); // 0 means play once

    // in future, we can add more functions to control volume, pause, resume, etc.

    // Clean up all loaded audio
    void clear_audio();
};

#endif // AUDIO_MANAGER_HPP

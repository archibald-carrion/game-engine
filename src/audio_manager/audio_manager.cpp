#include "audio_manager.hpp"
#include <iostream>

AudioManager::AudioManager() {
    std::cout << "AudioManager constructor" << std::endl;
}

AudioManager::~AudioManager() {
    std::cout << "AudioManager destructor" << std::endl;
    clear_audio();
}

void AudioManager::clear_audio() {
    for (auto& music : music_tracks) {
        Mix_FreeMusic(music.second);
    }
    for (auto& sound : sound_effects) {
        Mix_FreeChunk(sound.second);
    }
    music_tracks.clear();
    sound_effects.clear();
}

void AudioManager::add_music(const std::string& music_id, const std::string& file_path) {
    Mix_Music* music = Mix_LoadMUS(file_path.c_str());
    if (music == nullptr) {
        std::cerr << "[AudioManager] Failed to load music: " << Mix_GetError() << std::endl;
        return;
    }
    music_tracks.emplace(music_id, music);
}

Mix_Music* AudioManager::get_music(const std::string& music_id) {
    auto it = music_tracks.find(music_id);
    if (it != music_tracks.end()) {
        return it->second;
    }
    std::cerr << "[AudioManager] Music ID not found: " << music_id << std::endl;
    return nullptr;
}

void AudioManager::add_sound_effect(const std::string& sound_id, const std::string& file_path) {
    Mix_Chunk* sound = Mix_LoadWAV(file_path.c_str());
    if (sound == nullptr) {
        std::cerr << "[AudioManager] Failed to load sound effect: " << Mix_GetError() << std::endl;
        return;
    }
    sound_effects.emplace(sound_id, sound);
}

Mix_Chunk* AudioManager::get_sound_effect(const std::string& sound_id) {
    auto it = sound_effects.find(sound_id);
    if (it != sound_effects.end()) {
        return it->second;
    }
    std::cerr << "[AudioManager] Sound ID not found: " << sound_id << std::endl;
    return nullptr;
}

void AudioManager::play_music(const std::string& music_id, int loops) {
    Mix_Music* music = get_music(music_id);
    if (music != nullptr) {
        if (Mix_PlayMusic(music, loops) == -1) {
            std::cerr << "[AudioManager] Failed to play music: " << Mix_GetError() << std::endl;
        }
    }
}

void AudioManager::play_sound_effect(const std::string& sound_id, int loops) {
    Mix_Chunk* sound = get_sound_effect(sound_id);
    if (sound != nullptr) {
        if (Mix_PlayChannel(-1, sound, loops) == -1) {
            std::cerr << "[AudioManager] Failed to play sound effect: " << Mix_GetError() << std::endl;
        }
    }
}
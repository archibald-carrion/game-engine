/**
 * @file configuration.cpp
 * @brief Implementation of configuration file reading functionality.
 */

#include "configuration.hpp"

/**
 * @brief Reads the configuration file and populates the provided structures.
 * 
 * This function reads a configuration file named "config.txt" and populates
 * the window configuration, font configuration, and entity data structures.
 * 
 * @param window_config Pointer to the window_data structure to be populated
 * @param font Pointer to the window_font_config structure to be populated
 * @param entities Pointer to the vector of entity pointers to be populated
 */
void read_configuration_file(window_data* window_config, window_font_config* font, std::vector<entity*>* entities) {
    const std::string configFileName = "config.txt"; // Hardcoded filename, could be parameterized in future
    std::ifstream config_file_stream(configFileName);
    std::string config_content;
    size_t numerical_value; // Buffer used to store the result of string-to-number conversions

    // Read window configuration
    config_file_stream >> config_content; // Ignore first token (window flag)
    
    // Read window dimensions
    config_file_stream >> config_content; 
    window_config->width = std::stoi(config_content, &numerical_value);
    config_file_stream >> config_content; 
    window_config->height = std::stoi(config_content, &numerical_value);
    
    // Read window color
    window_config->window_color = new color();
    config_file_stream >> config_content; 
    window_config->window_color->r = std::stoi(config_content, &numerical_value);
    config_file_stream >> config_content; 
    window_config->window_color->g = std::stoi(config_content, &numerical_value);
    config_file_stream >> config_content; 
    window_config->window_color->b = std::stoi(config_content, &numerical_value);

    // Read font configuration
    config_file_stream >> config_content; // Ignore font flag
    
    // Read font folder
    config_file_stream >> config_content; 
    font->font_folder = config_content;
    
    // Read font color
    font->font_color = new color();
    config_file_stream >> config_content; 
    font->font_color->r = std::stoi(config_content, &numerical_value);
    config_file_stream >> config_content; 
    font->font_color->g = std::stoi(config_content, &numerical_value);
    config_file_stream >> config_content; 
    font->font_color->b = std::stoi(config_content, &numerical_value);
    
    // Read font size
    config_file_stream >> config_content; 
    font->font_size = std::stoi(config_content, &numerical_value);

    // Read entity data
    while(config_file_stream >> config_content) {
        // Ignore the entity flag
        entity* new_entity = new entity();
        
        // Read entity properties
        config_file_stream >> config_content;
        new_entity->label = config_content;
        
        config_file_stream >> config_content;
        new_entity->sprite_folder = config_content;
        
        config_file_stream >> config_content;
        new_entity->sprite_width = std::stoi(config_content, &numerical_value);
        
        config_file_stream >> config_content;
        new_entity->sprite_height = std::stoi(config_content, &numerical_value);
        
        config_file_stream >> config_content;
        new_entity->pos_X = std::stoi(config_content, &numerical_value);
        
        config_file_stream >> config_content;
        new_entity->pos_Y = std::stoi(config_content, &numerical_value);
        
        config_file_stream >> config_content;
        new_entity->speed_X = std::stoi(config_content, &numerical_value);
        
        config_file_stream >> config_content;
        new_entity->speed_Y = std::stoi(config_content, &numerical_value);
        
        config_file_stream >> config_content;
        std::string::size_type sz;
        new_entity->rotation = std::stod(config_content, &sz);
        
        entities->push_back(new_entity);
    }
}
#include "configuration.hpp"

void read_configuration_file(window_data* window_config, window_font* font, std::vector<entity*>* entities) {
    std::string configFileName = "config.txt"; // this value is hardcoded but could be received in future implementation
    std::ifstream config_file_stream(configFileName);
    std::string config_content;
    size_t numerical_value; // buffer used to cast the token stored as string to numerical values

    // read the data of the window
    config_file_stream >> config_content; // ignore first token, it's the flag window
    // read the width
    config_file_stream >> config_content; 
    window_config->width = std::stoi(config_content, &numerical_value);
    // read the height
    config_file_stream >> config_content; 
    window_config->height = std::stoi(config_content, &numerical_value);
    // allocate memory for the color of the window
    window_config->window_color = new color();
    // read r value of the color
    config_file_stream >> config_content; 
    window_config->window_color->r = std::stoi(config_content, &numerical_value);
    // read g value of the color
    config_file_stream >> config_content; 
    window_config->window_color->g = std::stoi(config_content, &numerical_value);
    // read b value of the color
    config_file_stream >> config_content; 
    window_config->window_color->b = std::stoi(config_content, &numerical_value);


    // read the data of the font
    config_file_stream >> config_content; // ignore first token, it's the flag font
    // read folder direction of the font
    config_file_stream >> config_content; 
    font->font_folder = config_content;
    // allocate memory for the font color
    font->font_color = new color();
    // read r value of the color
    config_file_stream >> config_content; 
    font->font_color->r = std::stoi(config_content, &numerical_value);
    // read g value of the color
    config_file_stream >> config_content; 
    font->font_color->g = std::stoi(config_content, &numerical_value);
    // read b value of the color
    config_file_stream >> config_content; 
    font->font_color->b = std::stoi(config_content, &numerical_value);
    // read size of the font
    config_file_stream >> config_content; 
    font->font_size = std::stoi(config_content, &numerical_value);


    // read the data of the entities
    // need a loop because there is between 0 and a lot of entities
    while(config_file_stream >> config_content) {
        // we ignore the first token as it's the entity label
        // allocate memory for new entity
        entity* new_entity = new entity();
        // read the name of the entity
        config_file_stream >> config_content;
        new_entity->label = config_content;
        // read the sprite folder of the entity
        config_file_stream >> config_content;
        new_entity->sprite_folder = config_content;
        // read the width of the sprite
        config_file_stream >> config_content;
        new_entity->sprite_width = std::stoi(config_content, &numerical_value);
        // read the height of the sprite
        config_file_stream >> config_content;
        new_entity->sprite_height = std::stoi(config_content, &numerical_value);
        // read the position on the axis X
        config_file_stream >> config_content;
        new_entity->pos_X = std::stoi(config_content, &numerical_value);
        // read the position on the axis Y
        config_file_stream >> config_content;
        new_entity->pos_Y = std::stoi(config_content, &numerical_value);
        // read the speed on the axis X
        config_file_stream >> config_content;
        new_entity->speed_X = std::stoi(config_content, &numerical_value);
        // read the speed on the axis Y
        config_file_stream >> config_content;
        new_entity->speed_Y = std::stoi(config_content, &numerical_value);
        // read the rotation value
        config_file_stream >> config_content;
        std::string::size_type sz;     // alias of size_t
        new_entity->rotation = std::stod(config_content, &sz);

        entities->push_back(new_entity);
    }


}
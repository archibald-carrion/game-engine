#include <fstream>
#include <iostream>
#include <string> // string, stoi
#include <vector>
#include <stdint.h> // int32_t, uint32_t, [...]

// struct made to store data about colors
struct color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t alpha;
};

// struct made to contain the data of the window, size and color
struct window_data{
    uint32_t width;
    uint32_t height;
    color* window_color;
};

struct window_font{
    std::string font_folder;
    color* font_color;
    uint8_t font_size;
};

struct entity{
    std::string label;
    std::string sprite_folder;
    uint32_t sprite_width;
    uint32_t sprite_height;
    int32_t pos_X;
    int32_t pos_Y;
    int32_t speed_X;
    int32_t speed_Y;
    double rotation; // in radian
};

void read_configuration_file(window_data* window_config, window_font* font, std::vector<entity*>* entities);
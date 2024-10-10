#ifndef TAG_COMPONENT_HPP
#define TAG_COMPONENT_HPP

#include <string>


struct TagComponent
{
   std::string tag;

   TagComponent(const std::string& tag = "") {
    this->tag = tag;
   }
};



#endif // TAG_COMPONENT_HPP
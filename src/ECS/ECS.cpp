#include "ECS.hpp"
#include <algorithm>

int IComponent::next_id = 0;

int Entity::get_id() const {
    return id;
}

void System::add_entity_to_system(Entity entity) {
    entities.push_back(entity);
}

void System::remove_entity_from_system(Entity entity) {
    auto it = std::remove_if(entities.begin(), entities.end(), [&entity](Entity other) {
        return entity == other;
    });
    entities.erase(it, entities.end());
}

std::vector<Entity> System::get_entities() const {
    return entities;
}

const Signature& System::get_signature() const {
    return componentSignature;
}

Registry::Registry() {
    std::cout<<"Registry constructor" << std::endl;
}
    
Registry::~Registry() {
    std::cout<<"Registry destructor" << std::endl;
}

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

Registry::Registry(){}
    
Registry::~Registry(){}

void Registry::update(){}
    
    //Entity management
Entity Registry::create_entity(){}


void Registry::kill_entity(Entity entity){}

    // // Component management
template <typename TComponent, typename... TArgs>
void Registry::add_component(Entity entity, TArgs&&... args){}

template <typename TComponent>
void Registry::remove_component(Entity entity){}

template <typename TComponent>
bool Registry::has_component(Entity entity){}

template <typename TComponent>
TComponent& Registry::get_component(Entity entity) const{

}

    // System management
template <typename TSystem, typename... TArgs>
void Registry::add_system(Entity entity, TArgs&&... args){

}

template <typename TSystem>
void Registry::remove_system(Entity entity) {}

template <typename TSystem>
bool Registry::has_system(Entity entity){}

template <typename TSystem>
TSystem& Registry::get_system(Entity entity) const{}

    // Add remove entities to systems
void Registry::add_entity_to_system(Entity entity){}
void Registry::remove_entity_from_system(Entity entity){}
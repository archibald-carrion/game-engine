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

// Registry::Registry(){}
    
// Registry::~Registry(){}

    
    //Entity management
Entity Registry::create_entity(){
    std::size_t entity_id;

    if(!free_ids.empty()){
        entity_id = free_ids.front();
        free_ids.pop_front();
    }else{
        entity_id = num_entities++;
        bool is_resize_needed = entity_id >= entityComponentSignatures.size();
        if(is_resize_needed){
            entityComponentSignatures.resize(entity_id + 100);
        }
    }

    Entity entity(entity_id);
    entities_to_be_added.insert(entity);
    std::cout<<"Entity created [Registry]" << std::endl;
    return entity;
}


void Registry::kill_entity(Entity entity){
    entities_to_be_killed.insert(entity);
}

//     // // Component management
// template <typename TComponent, typename... TArgs>
// void Registry::add_component(Entity entity, TArgs&&... args){}

// template <typename TComponent>
// void Registry::remove_component(Entity entity){

// }

// template <typename TComponent>
// bool Registry::has_component(Entity entity){}

// template <typename TComponent>
// TComponent& Registry::get_component(Entity entity) const{

// }

    // System management
// template <typename TSystem, typename... TArgs>
// void Registry::add_system(Entity entity, TArgs&&... args){

// }

// template <typename TSystem>
// void Registry::remove_system(Entity entity) {}

// template <typename TSystem>
// bool Registry::has_system(Entity entity){}

// template <typename TSystem>
// TSystem& Registry::get_system(Entity entity) const{}

    // Add remove entities to systems
void Registry::add_entity_to_system(Entity entity){
    const int entity_id = entity.get_id();
    const Signature& entity_component_signature = entityComponentSignatures[entity_id];

    for(auto& system : systems){
        const auto& system_component_signature = system.second->get_signature();
        bool is_compatible = (entity_component_signature & system_component_signature) == system_component_signature;
        if(is_compatible){
            system.second->add_entity_to_system(entity);
        }
    }
}

void Registry::remove_entity_from_system(Entity entity){
    for (auto& system : systems){
        system.second->remove_entity_from_system(entity);
    }
}

void Registry::update(){
    for (auto& entity : entities_to_be_added){
        add_entity_to_system(entity);
    }
    entities_to_be_added.clear();

    for(auto& entity: entities_to_be_killed) {
        remove_entity_from_system(entity);
        entityComponentSignatures[entity.get_id()].reset();
        free_ids.push_back(entity.get_id());

        //add id to free ids deque
    }
    entities_to_be_killed.clear();

}
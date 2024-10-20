#include "registry.hpp"

Registry::Registry() {
    std::cout<<"Registry constructor" << std::endl;
}
    
Registry::~Registry() {
    std::cout<<"Registry destructor" << std::endl;
}

Entity Registry::create_entity(){
    std::size_t entity_id;

    // if there are free ids, use one of them
    if(!free_ids.empty()){
        entity_id = free_ids.front();
        free_ids.pop_front();
    }else{
        // otherwise, create a new id
        entity_id = num_entities++;
        bool is_resize_needed = entity_id >= entityComponentSignatures.size();
        if(is_resize_needed){
            entityComponentSignatures.resize(entity_id + 100);
        }
    }

    Entity entity(entity_id);
    entity.registry = this;
    entities_to_be_added.insert(entity);
    return entity;
}

void Registry::kill_entity(Entity entity){
    entities_to_be_killed.insert(entity);
}

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
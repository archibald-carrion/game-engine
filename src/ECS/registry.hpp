#ifndef ECS_REGISTRY_HPP
#define ECS_REGISTRY_HPP

#include <bitset> 
#include <memory>
#include <unordered_map>
#include <set>
#include <typeindex>
#include <deque>
#include <vector>
#include <iostream>
#include "../utils/Pool.hpp"

#include "entity.hpp"
#include "system.hpp"

/**
 * @class Registry
 * @brief The Registry class represents the registry in the ECS system.
 */
class Registry {
private:
    std::vector<std::shared_ptr<IPool>> componentsPools; // pools of components
    std::vector<Signature> entityComponentSignatures; // signatures of the components of the entities

    std::unordered_map<std::type_index, std::shared_ptr<System>> systems; // systems in the registry
    std::set<Entity> entities_to_be_added; // entities to be added to the registry
    std::set<Entity> entities_to_be_killed; // entities to be deleted from the registry

    std::deque<int> free_ids; // deque containing free ids

public:
    int num_entities = 0; 
    Registry();
    
    ~Registry();

    void update();
    
    //Entity management
    Entity create_entity();
    void kill_entity(Entity entity);

    // Component management
    template <typename TComponent, typename... TArgs>
    void add_component(Entity entity, TArgs&&... args);

    template <typename TComponent>
    void remove_component(Entity entity);

    template <typename TComponent>
    bool has_component(Entity entity);

    template <typename TComponent>
    TComponent& get_component(Entity entity) const;

    // System management
    template <typename TSystem, typename... TArgs>
    void add_system(TArgs&&... args);

    template <typename TSystem>
    void remove_system(Entity entity);

    template <typename TSystem>
    bool has_system(Entity entity);

    template <typename TSystem>
    TSystem& get_system() const;

    // Add remove entities to systems
    void add_entity_to_system(Entity entity);
    void remove_entity_from_system(Entity entity);

    // reset the registry
    void clear_all_entities();

};

#endif // ECS_REGISTRY_HPP
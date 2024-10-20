#ifndef ECS_HPP
#define ECS_HPP

#include <bitset> 
#include <memory>
#include <unordered_map>
#include <set>
#include <typeindex>
#include <deque>
#include <vector>
#include <iostream>
#include "../utils/Pool.hpp"


const unsigned int MAX_COMPONENTS = 64; // Maximum number of components an entity can have

//Signature
typedef std::bitset<MAX_COMPONENTS> Signature; // Signature is a bitset that represents the components an entity has

/**
 * @class IComponent
 * @brief The IComponent class is an interface for the Component class.
 */
struct IComponent {
protected:
    static int next_id; // next id for the component
};

/**
 * @class Component
 * @brief The Component class is a template class for the components of an entity.
 */
template<typename TComponent>
class Component : public IComponent {
public:
    /**
     * @brief Get the id of the component
     * @return int The id of the component
     */
    static int get_id() {
        static int id = next_id++;
        return id;
    }
};

/**
 * @class Entity
 * @brief The Entity class represents an entity in the ECS system.
 */
class Entity {
private:
    int id; // id of the entity

public:
    /**
     * @brief Construct a new Entity object
     * @param id The id of the entity
     */
    Entity(int id) : id(id) {}
    
    /**
     * @brief Get the id of the entity
     * @return int The id of the entity
     */
    int get_id() const;

    /**
     * @brief Kill the entity
     */
    void kill();

    /**
     * @brief Check if the entity is alive
     * @return true if the entity is alive, false otherwise
     */
    bool operator==(const Entity& other) const {
        return id == other.id;
    }

    /**
     * @brief Check if the entity is not alive
     * @return true if the entity is not alive, false otherwise
     */
    bool operator!=(const Entity& other) const {
        return id != other.id;
    }

    /**
     * @brief Check if the entity is greater than another entity
     * @return true if the entity is greater than another entity, false otherwise
     */
    bool operator>(const Entity& other) const {
        return id > other.id;
    }

    /**
     * @brief Check if the entity is less than another entity
     * @return true if the entity is less than another entity, false otherwise
     */
    bool operator<(const Entity& other) const {
        return id < other.id;
    }

    /**
     * @brief Check if the entity is greater than or equal to another entity
     * @return true if the entity is greater than or equal to another entity, false otherwise
     */
    template <typename TComponent, typename... TArgs>
    void add_component(TArgs&&... args);

    /**
     * @brief Remove a component from the entity
     */
    template <typename TComponent>
    void remove_component();

    /**
     * @brief Check if the entity has a component
     * @return true if the entity has a component, false otherwise
     */
    template <typename TComponent>
    bool has_component();

    /**
     * @brief Get a component from the entity
     * @return TComponent& The component
     */
    template <typename TComponent>
    TComponent& get_component() const;

    class Registry* registry;
};

/**
 * @class System
 * @brief The System class represents a system in the ECS system.
 */
class System {
private:
    Signature componentSignature; // signature of the components the system operates on
    std::vector<Entity> entities; // entities on which this system operates

public:
    /**
     * @brief Construct a new System object
     */
    System()= default;

    /**
     * @brief Destroy the System object
     */
    ~System()= default;

    /**
     * @brief Update the system
     */
    void add_entity_to_system(Entity entity);

    /**
     * @brief Update the system
     */
    void remove_entity_from_system(Entity entity);

    /**
     * @brief Update the system
     */
    std::vector<Entity> get_entities() const;

    /**
     * @brief Update the system
     */
    const Signature& get_signature() const;

    /**
     * @brief Update the system
     */
    template<typename TComponent>
    void RequireComponent();
};


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

template<typename TComponent>
void System::RequireComponent() {
    const int component_id = Component<TComponent>::get_id();
    componentSignature.set(component_id);
}

template <typename TComponent, typename... TArgs>
void Registry::add_component(Entity entity, TArgs&&... args) {

    const size_t component_id = Component<TComponent>::get_id();
    const int entity_id = entity.get_id();
    if (component_id >= componentsPools.size()) {
        componentsPools.resize(component_id + 10);
    }

    if(!componentsPools[component_id]){
        std::shared_ptr<Pool<TComponent>> new_component_pool =
            std::make_shared<Pool<TComponent>>();
        componentsPools[component_id] = new_component_pool;
    }

    std::shared_ptr<Pool<TComponent>> component_pool =
        std::static_pointer_cast<Pool<TComponent>>(componentsPools[component_id]);

    if (entity_id >= component_pool->GetSize()) {
        component_pool->resize(entity_id + 10);
    }

    TComponent new_component(std::forward<TArgs>(args)...);

    component_pool->set(entity_id, new_component);
    entityComponentSignatures[entity_id].set(component_id);

    // std::cout << "component added to Registry, component id: " << component_id << " to entity :" << entity_id << std::endl;
}

template <typename TComponent>
void Registry::remove_component(Entity entity){
    const int component_id = Component<TComponent>::get_id();
    const int entity_id = entity.get_id();

    // Check if the component exists
    if (static_cast<size_t>(component_id) >= componentsPools.size()) {
        return;
    }

    // Check if the entity has the component
    if(!componentsPools[component_id]){
        return;
    }

    entityComponentSignatures[entity_id].set(component_id, false);
}

template <typename TComponent>
bool Registry::has_component(Entity entity) {
    const int component_id = Component<TComponent>::get_id();
    const int entity_id = entity.get_id();

    // Check if the component exists
    if (static_cast<size_t>(component_id) >= componentsPools.size()) {
        return false;
    }
    // Check if the entity has the component
    if(!componentsPools[component_id]){
        return false;
    }

    return entityComponentSignatures[entity_id].test(component_id);
}

template <typename TComponent>
TComponent& Registry::get_component(Entity entity) const{
    const size_t component_id = Component<TComponent>::get_id();
    const int entity_id = entity.get_id();

    // Check if the component exists
    if (component_id >= componentsPools.size()) {
        throw std::runtime_error("Component does not exist");
    }

    // Check if the entity has the component
    if(!componentsPools[component_id]){
        throw std::runtime_error("Component does not exist");
    }

    auto component_pool = std::static_pointer_cast<Pool<TComponent>>(componentsPools[component_id]);

    return component_pool->get(entity_id);
}

template <typename TSystem, typename... TArgs>
void Registry::add_system(TArgs&&... args) {
    std::shared_ptr<TSystem> new_system;
    
    if constexpr (sizeof...(TArgs) == 0) {
        new_system = std::make_shared<TSystem>();
    } else {
        new_system = std::make_shared<TSystem>(std::forward<TArgs>(args)...);
    }
    
    systems.insert(std::make_pair(std::type_index(typeid(TSystem)), new_system));
}

template <typename TSystem>
void Registry::remove_system(Entity entity) {
    auto system = systems.find(std::type_index(typeid(TSystem)));
    // Check if the system exists
    if (system == systems.end()) {
        return;
    }
    systems.erase(system);
}

template <typename TSystem>
bool Registry::has_system(Entity entity){
    auto system = systems.find(std::type_index(typeid(TSystem)));
    return system != systems.end();
}


template <typename TSystem>
TSystem& Registry::get_system() const{
    auto system = systems.find(std::type_index(typeid(TSystem)));
    // Check if the system exists
    if (system == systems.end()) {
        throw std::runtime_error("System does not exist");
    }
    return *std::static_pointer_cast<TSystem>(system->second); // get the system from the iterator because it is a pair
}





template <typename TComponent, typename... TArgs>
void Entity::add_component(TArgs&&... args) {
    registry->add_component<TComponent>(*this, std::forward<TArgs>(args)...);
}

template <typename TComponent>
void Entity::remove_component(){
    registry->remove_component<TComponent>(*this);
}

template <typename TComponent>
bool Entity::has_component(){
    return registry->has_component<TComponent>(*this);
}

template <typename TComponent>
TComponent& Entity::get_component() const{
    return registry->get_component<TComponent>(*this);
}


#endif // ECS_HPP
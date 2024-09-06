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
#include "../Utils/Pool.hpp"


const unsigned int MAX_COMPONENTS = 64;

//Signature
typedef std::bitset<MAX_COMPONENTS> Signature;

struct IComponent {
protected:
    static int next_id;
};

template<typename TComponent>
class Component : public IComponent {
public:
    static int get_id() {
        static int id = next_id++;
        return id;
    }

};


class Entity {
private:
    int id;

public:
    Entity(int id) : id(id) {}
    int get_id() const;

    bool operator==(const Entity& other) const {
        return id == other.id;
    }

    bool operator!=(const Entity& other) const {
        return id != other.id;
    }

    bool operator>(const Entity& other) const {
        return id > other.id;
    }

    bool operator<(const Entity& other) const {
        return id < other.id;
    }

    // Component management
    template <typename TComponent, typename... TArgs>
    void add_component(TArgs&&... args);

    template <typename TComponent>
    void remove_component();

    template <typename TComponent>
    bool has_component();

    template <typename TComponent>
    TComponent& get_component() const;

    class Registry* registry;

};


class System {
private:
    Signature componentSignature;
    std::vector<Entity> entities; // entities on which this system operates

public:
    System()= default;
    ~System()= default;

    void add_entity_to_system(Entity entity);
    void remove_entity_from_system(Entity entity);
    std::vector<Entity> get_entities() const;
    const Signature& get_signature() const;

    template<typename TComponent>
    void RequireComponent();
};

class Registry {
private:
    int num_entities = 0;
    std::vector<std::shared_ptr<IPool>> componentsPools;
    std::vector<Signature> entityComponentSignatures;

    std::unordered_map<std::type_index, std::shared_ptr<System>> systems;
    std::set<Entity> entities_to_be_added;
    std::set<Entity> entities_to_be_killed;

    std::deque<int> free_ids;

public:
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

    std::cout << "component added to Registry, component id: " << component_id << " to entity :" << entity_id << std::endl;
}

template <typename TComponent>
void Registry::remove_component(Entity entity){
    const int component_id = Component<TComponent>::get_id();
    const int entity_id = entity.get_id();

    // Check if the component exists
    if (component_id >= componentsPools.size()) {
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
    if (component_id >= componentsPools.size()) {
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
    const int component_id = Component<TComponent>::get_id();
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
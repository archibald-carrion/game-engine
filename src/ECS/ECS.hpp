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
    void add_system(Entity entity, TArgs&&... args);

    template <typename TSystem>
    void remove_system(Entity entity);

    template <typename TSystem>
    bool has_system(Entity entity);

    template <typename TSystem>
    TSystem& get_system(Entity entity) const;

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

    const int component_id = Component<TComponent>::get_id();
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
}



#endif // ECS_HPP
#ifndef ECS_HPP
#define ECS_HPP

#include <bitset>
#include <memory>
#include <vector>
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

};

template<typename TComponent>
void System::RequireComponent() {
    const int component_id = Component<TComponent>::get_id();
    componentSignature.set(component_id);
}



#endif // ECS_HPP
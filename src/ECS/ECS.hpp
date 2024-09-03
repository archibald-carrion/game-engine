#ifndef ECS_HPP
#define ECS_HPP

#include <memory>
#include <vector>
#include "../Utils/Pool.hpp"

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
};

class Registry {
private:
    int num_entities = 0;
    std::vector<std::shared_ptr<IPool>> componentsPools;

};



#endif // ECS_HPP
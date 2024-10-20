#ifndef ECS_HPP
#define ECS_HPP

#include "registry.hpp"









template<typename TComponent>
void System::RequireComponent() {
    const int component_id = Component<TComponent>::get_id();
    componentSignature.set(component_id);
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
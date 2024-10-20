#include "ECS.hpp"
#include <algorithm>
#include "../utils/Pool.hpp"


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




void Entity::kill() {
    registry->kill_entity(*this);
}

// void Registry::clear_all_entities() {
//     // Remove all entities from systems
//     for(int i = 0; i < num_entities; i++) {
//         Entity entity(i);
//         remove_entity_from_system(entity);
//     }

//     // Clear the component pools
//     for (auto& pool : componentsPools) {
//         if (pool) {
//             static_cast<Pool>(pool)->Clear();
//         }
//     }

//     // Reset all signatures
//     for (auto& signature : entityComponentSignatures) {
//         signature.reset();
//     }

//     // Clear entity management containers
//     entities_to_be_added.clear();
//     entities_to_be_killed.clear();

//     // Reset free IDs
//     free_ids.clear();
//     for (int i = 0; i < num_entities; i++) {
//         free_ids.push_back(i);
//     }

//     // Reset entity counter
//     num_entities = 0;
// }
void Registry::clear_all_entities() {
    // Remove all entities from systems
    for(int i = 0; i < num_entities; i++) {
        Entity entity(i);
        remove_entity_from_system(entity);
    }

    // Clear the component pools
    for (auto& pool : componentsPools) {
        if (pool) {
            pool->Clear();
        }
    }

    // Resize and reset all signatures
    entityComponentSignatures.clear();
    entityComponentSignatures.resize(100);

    // Clear entity management containers
    entities_to_be_added.clear();
    entities_to_be_killed.clear();

    // Reset free IDs
    free_ids.clear();

    // Reset entity counter
    num_entities = 0;
}
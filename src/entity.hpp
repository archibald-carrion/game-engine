#ifndef ENTITY_H
#define ENTITY_H

class IEntity {
protected:
    static int next_id; // shared between all class that inherit from IEntity
};

template<typename TypeEntity>
class Entity : public IEntity {
    public:
    static int get_id() {
        // static variable can only be initialized once
        static int id = next_id++;
        return id;
    }
};

class skull{
public:
    skull() = default;
};

class other_asset{
public:
    other_asset() = default;
};

#endif // ENTITY_H
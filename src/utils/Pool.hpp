#ifndef POOL_HPP
#define POOL_HPP

#include <vector>



class IPool {
public:
    virtual ~IPool() = default;
    virtual void Clear() = 0; // Add this pure virtual function
};

template <typename TComponent>
class Pool: public IPool {
private:
    std::vector<TComponent> data;

public:
    Pool(int size= 1000) {
        data.resize(size);
    }

    virtual ~Pool() = default;

    bool IsEmpty() const {
        return data.empty();
    }

    int GetSize() {
        return data.size();
    }

    void resize(int size) {
        data.resize(size);
    }

    void Clear() {
        data.clear();
    }


    void AddComponent(const TComponent& component) {
        data.push_back(component);
    }

    void set(unsigned int index, TComponent component) {
        data[index] = component;
    }


    TComponent& get(unsigned int index) {
        return data[index];
    }

    TComponent& operator[](unsigned int index) {
        return data[index];
    }

};    



#endif // POOL_HPP
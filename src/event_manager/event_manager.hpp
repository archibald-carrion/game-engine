#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include "event.hpp"
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <iostream>
#include <typeindex>

class IEventCallback {
private:
    virtual void call(Event& e) = 0;

public:
    virtual ~IEventCallback() = default;
    void execute(Event& e) {
        call(e);
    }
};

template <typename TOwner, typename TEvent>
class EventCallback : public IEventCallback {
private:
    typedef void(TOwner::*CallbackFunction)(TEvent&);
    TOwner* owner_instance;
    CallbackFunction callback_function;

    virtual void Call(Event& e) override {
        std::invoke(callback_function, owner_instance, static_cast<TEvent&> e);
    }

public: 
    EventCallback(TOwner* owner_instance, CallbackFunction callback_function) {
        this->callback_function = callback_function;
        this->owner_instance = owner_instance;
    }
};


typedef std::list<std::unique_ptr<IEventCallback>> handler_list;

class EventManager {
private:
    std::map<std::type_index, std::unique_ptr<handler_list>> subscribers;
public:
    EventManager() {
        std::cout << "EventManager constructor" << std::endl;
    }

    ~EventManager() {
        std::cout << "EventManager destructor" << std::endl;
    }

    void reset() {
        subscribers.clear();
    }

    template <typename TEvent, typename TOwner>
    void subscribe_to_event(TOwner* owner_instance, void (TOwner::*callbackFunction) (TEvent&)) {
        if(!subscribers[typeid(TEvent)].get()) {
            subscribers[typeid(TEvent)] = std::make_unique<handler_list>();
        }
        auto subscriber = std::make_unique<EventCallback<TOwner, TEvent>>(owner_instance, callbackFunction);
        subscribers[typeid(TEvent)]->push_back(std::move(subscriber))
    }

    template <typename TEvent, typename... TArgs>
    void emit_event(TArgs&&... args){
        auto handlers = subscribers[typeid(TEvent)].get();
        if(handlers) {
             for (auto it = handlers->begin(); it != handlers->end(); it++) {
                auto handler = it->get();
                TEvent event (std::forward<TArgs>(args)...);
                handler->execute(event);

             }
        }
    }
};

#endif // EVENT_MANAGER_HPP
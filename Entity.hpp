#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include "Component.hpp"
#include <iostream>
#include "ComponentMessaging.hpp"

class Component;

class Entity: public Handler, public Dispatcher {
public:
    virtual void update(double elapsed) = 0;
    template <class T>
    T getComponent() {
        for (Component *component: components) {
            if (dynamic_cast<T>(component) != NULL) {
                return (T)component;
            }
        }
        std::cout << "No component of class " << typeid(T).name() << std::endl;
        return nullptr;
    };
    virtual ~Entity() {
        std::cout << "Entity destructor called" << std::endl;
    }
protected:
    std::vector<Component *> components;
};

#endif

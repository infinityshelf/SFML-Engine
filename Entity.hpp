#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include "Component.hpp"
#include <iostream>

class Component;

class Entity {
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
protected:
    std::vector<Component *> components;
};

#endif

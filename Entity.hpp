#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "World.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Component.hpp"
#include <iostream>

class Entity {
public:
    sf::Vector2f position;
    virtual void update(double elapsed = 1.0) = 0;
    template <class T>
    T getComponent() {
        T result;
        for (Component *component: components) {
            if (dynamic_cast<T>(component) != NULL) {
                return  result;
            }
        }
        std::cout << "No component of class " << typeid(result).name() << std::endl;
        return nullptr;
    };
protected:
    std::vector<Component *> components;
};

#endif
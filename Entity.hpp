#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "World.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Component.hpp"
#include <iostream>

class Component;

class Entity {
public:
    sf::Vector2f position;
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
    virtual void sendMessage(Component *from, Component *to, std::string message) = 0;
protected:
    std::vector<Component *> components;
};

#endif
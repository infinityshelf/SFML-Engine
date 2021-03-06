//
// Created by Estevan Hernandez on 7/29/17.
//

#ifndef SFML_ENGINE_COMPONENT_HPP
#define SFML_ENGINE_COMPONENT_HPP

#include "Entity.hpp"
#include <iostream>
#include <SFML/System.hpp>

class Entity;

class Component {
public:
    int &identifier = identifier_;

    bool operator==(Component &other);
    bool operator!=(Component &other);

    virtual void update(double elapsed) = 0;
    virtual void siblingComponentsInitialized() = 0;

    virtual ~Component() { std::cout << "Component destructor called"; }

protected:
    Component(Entity &entity);
    static int current_id;
    int identifier_;
    Entity &entity_;
};


#endif //SFML_ENGINE_COMPONENT_HPP

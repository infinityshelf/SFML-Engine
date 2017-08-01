//
// Created by Estevan Hernandez on 7/29/17.
//

#ifndef SFML_ENGINE_COMPONENT_HPP
#define SFML_ENGINE_COMPONENT_HPP

#include "Entity.hpp"
#include <iostream>

class Entity;

class Component {
public:

    Component(Entity &parent);

    int identifier() {
        return identifier_;
    }

    bool operator==(Component &other);
    bool operator!=(Component &other);

    virtual void update(double elapsed) = 0;
protected:
    static int current_id;
    int identifier_;
    Entity &parent_;
};


#endif //SFML_ENGINE_COMPONENT_HPP

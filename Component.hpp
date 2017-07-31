//
// Created by Estevan Hernandez on 7/29/17.
//

#ifndef SFML_ENGINE_COMPONENT_HPP
#define SFML_ENGINE_COMPONENT_HPP

#include "Entity.hpp"

class Entity;

class Component {
public:

    Component();

    int identifier() {
        return identifier_;
    }

    bool operator==(Component &other);
    bool operator!=(Component &other);

    virtual void update(double elapsed) = 0;
    virtual void receiveMessage(Component *to, Component *from, std::string message) = 0;

protected:
    static int current_id;
    int identifier_;
};


#endif //SFML_ENGINE_COMPONENT_HPP

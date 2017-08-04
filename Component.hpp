//
// Created by Estevan Hernandez on 7/29/17.
//

#ifndef SFML_ENGINE_COMPONENT_HPP
#define SFML_ENGINE_COMPONENT_HPP

#include "Entity.hpp"

class Entity;

class Component {
public:
    virtual void update(double elapsed) = 0;
    Component();
    bool operator==(Component &other);
    bool operator!=(Component &other);
    int identifier() {return identifier_;}

protected:
    static int current_id;
    int identifier_;
};


#endif //SFML_ENGINE_COMPONENT_HPP

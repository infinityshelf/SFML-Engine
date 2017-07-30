//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PHYSICSCOMPONENT_HPP

#include "Entity.hpp"
#include "World.hpp"
#include "Component.hpp"

class PhysicsComponent: public Component {
public:
    virtual void update(double elapsed, Entity &entity) = 0;
    void update() override {

    }
};

#endif //SFML_ENGINE_PHYSICSCOMPONENT_HPP

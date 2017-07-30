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
    PhysicsComponent(Entity &entity, World &world): entity_(entity), world_(world) {

    }
protected:
    World &world_;
    Entity &entity_;
};

#endif //SFML_ENGINE_PHYSICSCOMPONENT_HPP
//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

#include "PhysicsComponent.hpp"

class PlayerPhysicsComponent: public PhysicsComponent {
public:
    PlayerPhysicsComponent();
    void update(double elapsed, Entity &entity) override;
private:
    sf::IntRect boundingBox;
    World *world;
};


#endif //SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

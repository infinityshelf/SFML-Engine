//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

#include "PhysicsComponent.hpp"

class PlayerPhysicsComponent: public PhysicsComponent {
public:
    PlayerPhysicsComponent(Entity &entity, World &world);
    //void update(double elapsed, Entity &entity) override;
    void update(double elapsed) override;
private:
    sf::IntRect boundingBox;
};


#endif //SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

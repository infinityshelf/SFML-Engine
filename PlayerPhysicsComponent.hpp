//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

#include "PhysicsComponent.hpp"

class PlayerPhysicsComponent: public PhysicsComponent {
public:
    sf::Vector2i position;
    PlayerPhysicsComponent(Entity &entity);
    void update(double elapsed) override;
    void setProposedVector(sf::Vector2i &proposedVector) {
        proposedVector_ = &proposedVector;
    }
private:
    sf::IntRect bbox;
    sf::IntRect projected_bbox;
    sf::Vector2i *proposedVector_;
};


#endif //SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

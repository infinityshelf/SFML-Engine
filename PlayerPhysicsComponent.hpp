//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

#include "PhysicsComponent.hpp"
#include "PlayerInputComponent.hpp"

class PlayerPhysicsComponent: public PhysicsComponent {
public:
    const sf::Vector2i &getPosition() { return position_; };
    PlayerPhysicsComponent(Entity &entity);
    void update(double elapsed) override;
    void setProposedVector(sf::Vector2i &proposedVector) {
        proposedVector_ = &proposedVector;
    }
    void siblingComponentsInitialized() override {
        proposedVector_ = &entity_.getComponent<PlayerInputComponent *>()->proposedVector();
    }
    bool onGround();
private:
    sf::Vector2i position_;
    sf::IntRect boundingBox_;
    sf::Vector2i *proposedVector_;
    int max_up;
    int max_right;
    int max_left;
    int max_down;
    void clampValues(sf::Vector2i *vector);
};


#endif //SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

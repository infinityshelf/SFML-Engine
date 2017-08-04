//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP
#define SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

#include "InputComponent.hpp"
#include "PlayerPhysicsComponent.hpp"

class PlayerPhysicsComponent;

class PlayerInputComponent: public InputComponent {
public:
    void update(double elapsed) override;
    PlayerInputComponent(Entity &entity);

private:
    sf::Vector2i proposedVector_;
    void siblingComponentsInitialized() override {
        parent_.getComponent<PlayerPhysicsComponent *>()->setProposedVector(proposedVector_);
    }
};


#endif //SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP
#define SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

#include "InputComponent.hpp"

class PlayerInputComponent: public InputComponent {
public:
    sf::Vector2i &proposedVector() { return proposedVector_; };
    void update(double elapsed) override;
    PlayerInputComponent(Entity &entity);

private:
    sf::Vector2i proposedVector_;
    void siblingComponentsInitialized() override;
    int moveSpeed_;
    int jumpHeight_;
    const bool *grounded_;
};


#endif //SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerInputComponent.hpp"
#include <iostream>
#include <sstream>
#include "Input.hpp"
#include "PlayerPhysicsComponent.hpp"

const bool debug = false;

void PlayerInputComponent::update(double elapsed) {
    if (debug) std::cout << "Entity: " << &entity_ << " PlayerInputComponent::update" << std::endl;
    if (debug) Input::inputStruct.log();
    
    if (Input::inputStruct.right) {
        proposedVector_.x += moveSpeed_ * elapsed;
    }
    if (Input::inputStruct.left) {
        proposedVector_.x -= moveSpeed_ * elapsed;
    }

    if (Input::inputStruct.left == false && Input::inputStruct.right == false) {
        proposedVector_.x *= 0.5;
    }

    if (Input::inputStruct.upPressed && *grounded_) {
        proposedVector_.y -= elapsed * jumpHeight_;
    }
}

PlayerInputComponent::PlayerInputComponent(Entity &entity): InputComponent(entity) {


}

void PlayerInputComponent::siblingComponentsInitialized() {
    PlayerPhysicsComponent *physicsComponent;
    physicsComponent = entity_.getComponent<PlayerPhysicsComponent *>();

    moveSpeed_ = physicsComponent->moveSpeed();
    jumpHeight_ = physicsComponent->jumpHeight();
    grounded_ = physicsComponent->grounded;
}

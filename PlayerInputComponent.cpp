//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerInputComponent.hpp"
#include <iostream>
#include <sstream>
#include "Input.hpp"
#include "Player.hpp"

const bool debug = false;
const uint8_t move = 5;

void PlayerInputComponent::update(double elapsed) {
    if (debug) std::cout << "Entity: " << &entity_ << " PlayerInputComponent::update" << std::endl;
    if (debug) Input::inputStruct.log();

    proposedVector_.x = proposedVector_.y = 0;
    
    if (Input::inputStruct.right) {
        proposedVector_.x += move * elapsed;
    }
    if (Input::inputStruct.left) {
        proposedVector_.x -= move * elapsed;
    }
    if (Input::inputStruct.up) {
        proposedVector_.y -= move * elapsed;
    }
    if (Input::inputStruct.down) {
        proposedVector_.y += move * elapsed;
    }
}

PlayerInputComponent::PlayerInputComponent(Entity &entity, PlayerPhysicsComponent &physicsComponent): physicsComponent_(physicsComponent),InputComponent(entity) {
    physicsComponent_.setProposedVector(proposedVector_);

}
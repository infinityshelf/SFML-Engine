//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerInputComponent.hpp"
#include <iostream>
#include <sstream>
#include "Input.hpp"
#include "PlayerPhysicsComponent.hpp"

class PlayerPhysicsComponent;

const bool debug = false;
const uint8_t move = 2;
const uint8_t jumpHeight = 50;

void PlayerInputComponent::update(double elapsed) {
    if (debug) std::cout << "Entity: " << &entity_ << " PlayerInputComponent::update" << std::endl;
    if (debug) Input::inputStruct.log();
    
    if (Input::inputStruct.right) {
        proposedVector_.x += move * elapsed;
    }
    if (Input::inputStruct.left) {
        proposedVector_.x -= move * elapsed;
    }

    if (Input::inputStruct.left == false && Input::inputStruct.right == false) {
        proposedVector_.x *= 0.5;
    }

    if (Input::inputStruct.upPressed && parent_.getComponent<PlayerPhysicsComponent *>()->onGround()) {
        proposedVector_.y -= elapsed * jumpHeight;
    }
}

PlayerInputComponent::PlayerInputComponent(Entity &entity): InputComponent(entity) {


}
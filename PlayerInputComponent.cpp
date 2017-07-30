//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerInputComponent.hpp"
#include <iostream>
#include "Input.hpp"
#include "Player.hpp"

const bool debug = false;
const uint8_t move = 2;

void PlayerInputComponent::update(double elapsed) {
    if (debug) std::cout << "Entity: " << &entity_ << " PlayerInputComponent::update" << std::endl;
    if (debug) Input::inputStruct.log();
    if (Input::inputStruct.right) {
        entity_.position.x += move * elapsed;
    }
    if (Input::inputStruct.left) {
        entity_.position.x -= move * elapsed;
    }
    if (Input::inputStruct.up) {
        entity_.position.y -= move * elapsed;
    }
    if (Input::inputStruct.down) {
        entity_.position.y += move * elapsed;
    }
}

PlayerInputComponent::PlayerInputComponent(Entity &entity): InputComponent(entity) {

}
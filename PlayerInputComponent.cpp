//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerInputComponent.hpp"
#include <iostream>
#include "Input.hpp"

const bool debug = false;

void PlayerInputComponent::update(Entity &entity) {
    if (debug) std::cout << "Entity: " << &entity << " PlayerInputComponent::update" << std::endl;
    if (debug) Input::inputStruct.log();
    if (Input::inputStruct.right) {
        entity.position.x += 1;
    }
    if (Input::inputStruct.left) {
        entity.position.x -= 1;
    }
    if (Input::inputStruct.up) {
        entity.position.y -= 1;
    }
    if (Input::inputStruct.down) {
        entity.position.y += 1;
    }
}
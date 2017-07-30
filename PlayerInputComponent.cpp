//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerInputComponent.hpp"
#include <iostream>
#include "Input.hpp"
#include "Player.hpp"

const bool debug = false;
const uint8_t move = 2;

void PlayerInputComponent::update(double elapsed, Entity &entity) {
    if (debug) std::cout << "Entity: " << &entity << " PlayerInputComponent::update" << std::endl;
    if (debug) Input::inputStruct.log();
    if (Input::inputStruct.right) {
        entity.position.x += move * elapsed;
    }
    if (Input::inputStruct.left) {
        entity.position.x -= move * elapsed;
    }
    if (Input::inputStruct.up) {
        entity.position.y -= move * elapsed;
    }
    if (Input::inputStruct.down) {
        entity.position.y += move * elapsed;
    }
}
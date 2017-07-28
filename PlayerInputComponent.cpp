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
}
//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerInputComponent.hpp"
#include <iostream>
#include "Input.hpp"

const bool debug = false;

void PlayerInputComponent::update(Entity &entity, sf::RenderWindow &window_ref) {
    if (debug) std::cout << "Entity: " << &entity << " PlayerInputComponent::update" << std::endl;
    if (debug) std::cout << "window_ref: " << &window_ref << std::endl;
}
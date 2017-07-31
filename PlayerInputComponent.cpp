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
    sf::Vector2f velocity(0,0);
    if (Input::inputStruct.right) {
        entity_.position.x += move * elapsed;
        velocity.x += move * elapsed;
    }
    if (Input::inputStruct.left) {
        entity_.position.x -= move * elapsed;
        velocity.x -= move * elapsed;
    }
    if (Input::inputStruct.up) {
        entity_.position.y -= move * elapsed;
        velocity.y -= move * elapsed;
    }
    if (Input::inputStruct.down) {
        entity_.position.y += move * elapsed;
        velocity.y += move * elapsed;
    }
    Component *to = entity_.getComponent<PlayerPhysicsComponent *>();
    std::stringstream buffer;
    buffer << "I want to go to x: " << velocity.x << " y: " << velocity.y << std::endl;
    entity_.sendMessage(this, to, buffer.str());
}

PlayerInputComponent::PlayerInputComponent(Entity &entity): InputComponent(entity) {

}
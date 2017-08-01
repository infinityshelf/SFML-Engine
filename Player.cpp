#include "Player.hpp"
#include <iostream>

const bool debug = false;

Player::~Player() {

}

void Player::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;
    for (Component *component: components) {
        component->update(elapsed);
    }
}

Player::Player() {

    PlayerPhysicsComponent *physicsComponent = new PlayerPhysicsComponent(*this);
    PlayerGraphicsComponent *graphicsComponent =  new PlayerGraphicsComponent(*this, *physicsComponent);
    PlayerInputComponent *inputComponent = new PlayerInputComponent(*this, *physicsComponent);

    components.push_back((Component *)inputComponent);
    components.push_back((Component *)physicsComponent);
    components.push_back((Component *)graphicsComponent);
}

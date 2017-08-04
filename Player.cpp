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
    components.push_back(new PlayerInputComponent(*this));
    components.push_back(new PlayerPhysicsComponent(*this));
    components.push_back(new PlayerGraphicsComponent(*this));
    for (Component *component: components) {
        component->siblingComponentsInitialized();
    }
}

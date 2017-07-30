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

Player::Player(sf::RenderWindow &window_ref){
    components.push_back(new PlayerGraphicsComponent(*this, window_ref));
    components.push_back(new PlayerPhysicsComponent(*this, *World::instance()));
    components.push_back(new PlayerInputComponent(*this));
    PlayerPhysicsComponent *comp;
    comp = getComponent<PlayerPhysicsComponent *>();
    if (comp) {
        std::cout << "found the component!" << std::endl;
    } else {
        std::cout << "could not find the component!" << std::endl;
    }

}

#include "Player.hpp"
#include <iostream>

const bool debug = false;

Player::~Player() {
    for (Component *component: components) {
        delete component;
    }

}

void Player::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;
    for (Component *component: components) {
        component->update(elapsed);
    }
}

Player::Player(sf::RenderWindow &window_ref){
    components.push_back(new PlayerGraphicsComponent(*this));
    components.push_back(new PlayerPhysicsComponent(*this));
    components.push_back(new PlayerInputComponent(*this));
}

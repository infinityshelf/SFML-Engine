#include "Player.hpp"
#include <iostream>

const bool debug = false;

Player::~Player() {
    /*
    for (Component *component: components) {
        delete component;
    }
    */

}

void Player::update(double elapsed) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;
    for (Component *component: components) {
        component->update(elapsed);
    }
}

void Player::sendMessage(Component *from, Component *to, std::string message) {
    for (Component *comp: components) {
        if (comp == to) {
            comp->receiveMessage(to, from, message);
        }
    }
}

Player::Player(sf::RenderWindow &window_ref) {
    components.push_back(new PlayerInputComponent(*this));
    components.push_back(new PlayerPhysicsComponent(*this));
    components.push_back(new PlayerGraphicsComponent(*this));
}

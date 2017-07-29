#include "Player.hpp"
#include <iostream>

const bool debug = false;

Player::~Player() {

}

void Player::update(double elapsed, sf::RenderWindow &window_ref) {
    if (debug) std::cout << "elapsed: " << elapsed << std::endl;
    input_->update(elapsed, *this);
    graphics_->update(*this, window_ref);
}
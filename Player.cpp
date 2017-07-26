#include "Player.hpp"

Player::~Player() {

}

void Player::update(double elapsed, sf::RenderWindow &window_ref) {
    input_->update(*this, window_ref);
    graphics_->update(*this, window_ref);
}
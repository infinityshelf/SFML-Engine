#include "Player.hpp"

Player::~Player() {

}

void Player::update(double elapsed, sf::RenderWindow &window) {
    circleBlue.move(sf::Vector2f(2.0 * elapsed, 0.0));
    circleRed.move(sf::Vector2f(2.0, 0.0));
    window.draw(circleBlue);
    window.draw(circleRed);
}
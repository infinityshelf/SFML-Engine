#include "Player.hpp"

Player::~Player() {

}

void Player::update(double elapsed, sf::RenderWindow &window) {
    circleBlue.move(sf::Vector2f(1 * elapsed, 0));
    circleRed.move(sf::Vector2f(1, 0));
    window.draw(circleBlue);
    window.draw(circleRed);
}
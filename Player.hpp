#ifndef PLAYER_HPP
#define PLAYER_HPP value

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "PlayerGraphicsComponent.hpp"
#include "PlayerInputComponent.hpp"

class PlayerGraphicsComponent;

class Player: public Entity {
public:
    Player(PlayerGraphicsComponent *graphics, PlayerInputComponent *input):graphics_(graphics), input_(input) {

    };
    ~Player();
    void update(double elapsed, sf::RenderWindow &window) override;
private:
    PlayerGraphicsComponent *graphics_;
    PlayerInputComponent *input_;
};

#endif
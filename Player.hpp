#ifndef PLAYER_HPP
#define PLAYER_HPP value

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "PlayerGraphicsComponent.hpp"
#include "PlayerInputComponent.hpp"
#include "PlayerPhysicsComponent.hpp"

class Player: public Entity {
public:
    Player(sf::RenderWindow &window_ref);
    ~Player();
    void update(double elapsed) override;
};

#endif
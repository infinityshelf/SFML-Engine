#ifndef PLAYER_HPP
#define PLAYER_HPP value

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "GraphicsComponent.hpp"
#include "InputComponent.hpp"

class Player: public Entity {
public:
    Player(GraphicsComponent *graphics, InputComponent *input):graphics_(graphics), input_(input) {

    };
    ~Player();
    void update(double elapsed, sf::RenderWindow &window) override;
private:
    GraphicsComponent *graphics_;
    InputComponent *input_;
};

#endif
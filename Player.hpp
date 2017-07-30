#ifndef PLAYER_HPP
#define PLAYER_HPP value

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "GraphicsComponent.hpp"
#include "InputComponent.hpp"
#include "PhysicsComponent.hpp"
#include "PlayerPhysicsComponent.hpp"

class Player: public Entity {
public:
    Player(GraphicsComponent *graphics, InputComponent *input, PhysicsComponent *physics):graphics_(graphics), input_(input), physics_(physics){
        components.push_back(graphics_);
        components.push_back(physics_);
        components.push_back(input_);
        PlayerPhysicsComponent *comp;
        comp = getComponent<PlayerPhysicsComponent *>();
        if (comp) {
            std::cout << "found the component!" << std::endl;
        } else {
            std::cout << "could not find the component!" << std::endl;
        }
        
    };
    ~Player();
    void update(double elapsed, sf::RenderWindow &window) override;
public:
    GraphicsComponent *graphics_;
    InputComponent *input_;
    PhysicsComponent *physics_;
};

#endif
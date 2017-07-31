//
// Created by Estevan Hernandez on 7/28/17.
//

#ifndef SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

#include "PhysicsComponent.hpp"

class PlayerPhysicsComponent: public PhysicsComponent {
public:
    PlayerPhysicsComponent(Entity &entity);
    //void update(double elapsed, Entity &entity) override;
    void update(double elapsed) override;
    void receiveMessage(Component *from, Component *to, std::string message) override {
        std::cout << "Component: " << from << typeid(from).name() << " says to: " << to << typeid(to).name() << " message: " << message << std::endl;
    }
private:
    sf::IntRect boundingBox;
};


#endif //SFML_ENGINE_PLAYERPHYSICSCOMPONENT_HPP

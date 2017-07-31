//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP
#define SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

#include "InputComponent.hpp"

class PlayerInputComponent: public InputComponent {
public:
    //void update(double elapsed, Entity &entity) override;
    void update(double elapsed) override;
    PlayerInputComponent(Entity &entity);
    void receiveMessage(Component *from, Component *to, std::string message) override {
        std::cout << "Component: " << from << typeid(from).name() << " says to: " << to << typeid(to).name() << " message: " << message << std::endl;
    }
};


#endif //SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

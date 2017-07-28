//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP
#define SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

#include "InputComponent.hpp"

class PlayerInputComponent: public InputComponent {
public:
    void update(Entity &entity) override;
};


#endif //SFML_ENGINE_PLAYERINPUTCOMPONENT_HPP

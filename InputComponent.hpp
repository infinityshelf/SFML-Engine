//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_INPUTCOMPONENT_HPP
#define SFML_ENGINE_INPUTCOMPONENT_HPP

#include "InputStruct.hpp"
#include "Entity.hpp"
#include "InputStruct.hpp"

class InputComponent {
public:
    virtual void update(double elapsed, Entity &entity) = 0;
};


#endif //SFML_ENGINE_INPUTCOMPONENT_HPP

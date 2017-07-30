//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_INPUTCOMPONENT_HPP
#define SFML_ENGINE_INPUTCOMPONENT_HPP

#include "InputStruct.hpp"
#include "Entity.hpp"
#include "InputStruct.hpp"
#include "Component.hpp"

class InputComponent: public Component {
public:
    virtual void update(double elapsed, Entity &entity) = 0;
    void update() override {

    }
};


#endif //SFML_ENGINE_INPUTCOMPONENT_HPP

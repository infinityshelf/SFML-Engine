//
// Created by Estevan Hernandez on 7/29/17.
//

#ifndef SFML_ENGINE_COMPONENT_HPP
#define SFML_ENGINE_COMPONENT_HPP


class Component {
public:
    virtual void update(double elapsed = 1.0) = 0;
};


#endif //SFML_ENGINE_COMPONENT_HPP

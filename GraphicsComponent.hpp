//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_GRAPHICSCOMPONENT_HPP
#define SFML_ENGINE_GRAPHICSCOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class GraphicsComponent {
public:
    virtual void update(Entity &entity, sf::RenderWindow &window_ref) = 0;

};


#endif //SFML_ENGINE_GRAPHICSCOMPONENT_HPP

//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_GRAPHICSCOMPONENT_HPP
#define SFML_ENGINE_GRAPHICSCOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Component.hpp"

class GraphicsComponent: public Component {
public:
    GraphicsComponent(Entity &entity, sf::RenderWindow &renderWindow): entity_(entity), renderWindow_(renderWindow) {

    }
protected:
    Entity &entity_;
    sf::RenderWindow &renderWindow_;
};


#endif //SFML_ENGINE_GRAPHICSCOMPONENT_HPP

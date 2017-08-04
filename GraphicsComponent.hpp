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
    static void setWindow(sf::RenderWindow *window) {
        s_window = window;
    }
    GraphicsComponent(Entity &entity): Component(entity), entity_(entity) {

    }
protected:
    static sf::RenderWindow *s_window;
    //sf::RenderWindow &renderWindow_;
    Entity &entity_;
};


#endif //SFML_ENGINE_GRAPHICSCOMPONENT_HPP

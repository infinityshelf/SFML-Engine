//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerGraphicsComponent.hpp"
#include <iostream>

const bool debug = false;

void PlayerGraphicsComponent::update(Entity &entity, sf::RenderWindow &window_ref) {
    if (debug) std::cout << "Entity: " << &entity << " PlayerGraphicsComponent::update" << std::endl;
    for (sf::Drawable *drawable : entity.drawables) {
        window_ref.draw(*drawable);
    }
}
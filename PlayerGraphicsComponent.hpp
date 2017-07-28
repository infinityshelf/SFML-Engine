//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP

#include "GraphicsComponent.hpp"
#include "Player.hpp"

class Player;

class PlayerGraphicsComponent: public GraphicsComponent {
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    PlayerGraphicsComponent();
    void update(Entity &entity, sf::RenderWindow &window_ref) override;
};


#endif //SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP

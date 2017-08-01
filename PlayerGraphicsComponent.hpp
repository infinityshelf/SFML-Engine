//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP

#include "GraphicsComponent.hpp"
#include "Player.hpp"
#include "PlayerPhysicsComponent.hpp"

extern const std::string kRobo;
extern const std::string kRoboFilePath;

class Player;

class PlayerGraphicsComponent: public GraphicsComponent {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    PlayerPhysicsComponent &physicsComponent_;
public:
    PlayerGraphicsComponent(Entity &entity, PlayerPhysicsComponent &physicsComponent);
    void update(double elapsed) override;
};


#endif //SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP

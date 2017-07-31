//
// Created by Estevan Hernandez on 7/25/17.
//

#ifndef SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP
#define SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP

#include "GraphicsComponent.hpp"
#include "Player.hpp"

extern const std::string kRobo;
extern const std::string kRoboFilePath;

class Player;

class PlayerGraphicsComponent: public GraphicsComponent {
private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    PlayerGraphicsComponent(Entity &entity);
    void update(double elapsed) override;
    void receiveMessage(Component *from, Component *to, std::string message) override {
        std::cout << "Component: " << from << typeid(from).name() << " says to: " << to << typeid(to).name() << " message: " << message << std::endl;
    }
};


#endif //SFML_ENGINE_PLAYERGRAPHICSCOMPONENT_HPP

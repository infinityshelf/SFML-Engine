//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerGraphicsComponent.hpp"
#include "TextureManager.hpp"
#include <iostream>
#include <cassert>
#include "PlayerPhysicsComponent.hpp"

const bool debug = false;
const std::string kRobo = "robo";
const std::string kRoboFilePath = "robo.png";

void PlayerGraphicsComponent::update(double elapsed) {
    if (debug) std::cout << elapsed << std::endl;
    sprite.setPosition((float) position->x, (float) position->y);
    assert(GraphicsComponent::s_window != nullptr);
    GraphicsComponent::s_window->draw(sprite);
}

PlayerGraphicsComponent::PlayerGraphicsComponent(Entity &entity) : GraphicsComponent(entity) {
    TextureManager *textureManager = TextureManager::instance();
    textureManager->loadTexture(kRobo, kRoboFilePath);
    this->sprite.setTexture(TextureManager::instance()->getRef(kRobo));
    this->sprite.setTextureRect(sf::IntRect(0,0,35,81));
    this->sprite.setScale(2,2);
}

void PlayerGraphicsComponent::siblingComponentsInitialized() {
    position = &entity_.getComponent<PlayerPhysicsComponent *>()->getPosition();
}

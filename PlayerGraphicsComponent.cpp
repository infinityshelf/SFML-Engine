//
// Created by Estevan Hernandez on 7/25/17.
//

#include "PlayerGraphicsComponent.hpp"
#include "TextureManager.hpp"
#include <iostream>

const bool debug = false;

PlayerGraphicsComponent::PlayerGraphicsComponent() {
    //sf::Image image;
    //image.loadFromFile("mmbn6.png");
    //image.createMaskFromColor(sf::Color(201,247,194));
    //sf::Texture texture;
    //texture.loadFromImage(image);
    //this->sprite.setTexture(texture);
    TextureManager *textureManager = TextureManager::instance();
    textureManager->loadTexture(kRobo, kRoboFilePath);
    this->sprite.setTexture(TextureManager::instance()->getRef(kRobo));
    this->sprite.setTextureRect(sf::IntRect(0,0,35,81));
}

void PlayerGraphicsComponent::update(Entity &entity, sf::RenderWindow &window_ref) {
    if (debug) std::cout << "Entity: " << &entity << " PlayerGraphicsComponent::update" << std::endl;
    if (debug) std::cout << "window_ref" << &window_ref << std::endl;
    this->sprite.setPosition(entity.position);
    window_ref.draw(this->sprite);
}
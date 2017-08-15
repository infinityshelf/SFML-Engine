#include "World.hpp"
#include <iostream>

const bool debug = false;

void World::update(double elapsed, sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
    static double avg;
    avg = (avg + elapsed) / 2.0;
    if (debug) {
        std::cout << "elapsed: " << elapsed << std::endl;
        std::cout << "average: " << avg << std::endl;
    }
    for (Entity *entity: entities) {
        entity->update(elapsed);
    }
    for (sf::IntRect *rect: collidables) {
        rectShape.setSize(sf::Vector2f(rect->width, rect->height));
        rectShape.setPosition(sf::Vector2f(rect->left, rect->top));
        rectShape.setFillColor(sf::Color(0,0x80,0x40,0xFF));
        window.draw(rectShape);
    }
    window.display();
}
// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World/World.hpp"

const int targetFrameRate = 80;
const bool microseconds = true;

int main(int argc, char const *argv[]) {
    std::cout << argc << std::endl;

    World *world = World::instance();

    sf::RenderWindow window(sf::VideoMode(1920, 1080, 8), argv[1], sf::Style::Titlebar|sf::Style::Close);
    window.setFramerateLimit(targetFrameRate);
    window.setVerticalSyncEnabled(false);

    // Game Loop
    sf::Clock elapsedClock;
    elapsedClock.restart();
    while (window.isOpen()) {
        double elapsed;
        if (microseconds) {
            elapsed = elapsedClock.restart().asMicroseconds() / (1000000.0 / (double) targetFrameRate);
        } else {
            elapsed = elapsedClock.restart().asMilliseconds() / (1000.0 / (double) targetFrameRate);
        }
        world->update(elapsed);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }

    return EXIT_SUCCESS;
}
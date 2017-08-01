// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "Player.hpp"
#include "Input.hpp"
#include "PlayerGraphicsComponent.hpp"
#include "PlayerInputComponent.hpp"
#include "PlayerPhysicsComponent.hpp"

#define VARIABLE_TIME_STEP false

const int targetFrameRate = 60;

int main(int argc, char const *argv[]) {
    std::cout << argc << std::endl;

    sf::RenderWindow window(sf::VideoMode(640, 480, 8), argv[1], sf::Style::Titlebar|sf::Style::Close);
    window.setFramerateLimit(targetFrameRate);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setTitle("SFML-Engine");
    GraphicsComponent::setWindow(&window);

    World *world = World::instance();

    for (int i = 0; i < 640 / 32; i++) {
        for (int j = 0; j < 480 / 32; j++) {
            if (i == 0 || j == 0 || i == (640 / 32) - 1 || j == (480 / 32) - 1) {
                world->addCollidable(new sf::IntRect(i * 32, j * 32, 32, 32));
            }
        }
    }
    Player *player = new Player();
    world->addEntity(player);

#if VARIABLE_TIME_STEP
    sf::Clock elapsedClock;
    static double elapsed;
#endif
    Input::clearInput();
    while (window.isOpen()) {
        Input::getInput(window);
#if VARIABLE_TIME_STEP
        elapsed = elapsedClock.restart().asMilliseconds() / (1000.0 / (double) targetFrameRate);
        world->update(elapsed, window);
#else
        world->update(1.0, window);
#endif

    }

    return EXIT_SUCCESS;
}

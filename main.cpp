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

#define VARIABLE_TIME_STEP true

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
    sf::IntRect collider0(64,64,32,32);
    world->addCollidable(&collider0);
    sf::IntRect collider1(64,480-128,32,32);
    world->addCollidable(&collider1);
    Player *player = new Player();
    world->addEntity(player);

    sf::Clock elapsedClock;
#if VARIABLE_TIME_STEP
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

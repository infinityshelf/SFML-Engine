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

const int targetFrameRate = 120;

int main(int argc, char const *argv[]) {
    std::cout << argc << std::endl;

    sf::RenderWindow window(sf::VideoMode(240*4, 160*4, 8), argv[1], sf::Style::Titlebar|sf::Style::Close);
    window.setFramerateLimit(targetFrameRate);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setTitle("SFML-Engine");

    World *world = World::instance();
    //Player *player = new Player( new PlayerGraphicsComponent(*player, window), new PlayerInputComponent, new PlayerPhysicsComponent);
    Player *player = new Player(window);
    world->addEntity(player);

    sf::Clock elapsedClock;
    static double elapsed;
    Input::clearInput();
    while (window.isOpen()) {
        Input::getInput(window);
        elapsed = elapsedClock.restart().asMilliseconds() / (1000.0 / (double) targetFrameRate);
        world->update(elapsed, window);
    }

    return EXIT_SUCCESS;
}
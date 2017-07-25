// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World/World.hpp"
#include "Player/Player.hpp"
#include "Input/Input.hpp"

const int targetFrameRate = 60;

int main(int argc, char const *argv[]) {
    std::cout << argc << std::endl;

    World *world = World::instance();
    Player *player = new Player;
    world->addEntity(player);

    sf::RenderWindow window(sf::VideoMode(1920, 1080, 8), argv[1], sf::Style::Titlebar|sf::Style::Close);
    window.setFramerateLimit(targetFrameRate);
    window.setVerticalSyncEnabled(false);

    Input *input = Input::instance();

    // Game Loop
    sf::Clock elapsedClock;
    static double elapsed;
    while (window.isOpen()) {
        elapsed = elapsedClock.restart().asMilliseconds() / (1000.0 / (double) targetFrameRate);
        input->getInput(window);
        world->update(elapsed, window);
    }

    return EXIT_SUCCESS;
}
// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "World.hpp"
#include "Player.hpp"
#include "Input.hpp"

#define VARIABLE_TIME_STEP false

const int targetFrameRate = 60;

int main(int argc, char const *argv[]) {
    std::cout << argc << std::endl;
    int width = 160*9;
    int height = 160*4;
    sf::RenderWindow window(sf::VideoMode(width, height, 8), argv[1], sf::Style::Titlebar|sf::Style::Close);
    window.setFramerateLimit(targetFrameRate);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.setTitle("SFML-Engine");
    GraphicsComponent::setWindow(&window);

    World *world = World::instance();

    int blockSize = 32;
    for (int i = 0; i < width / blockSize; i++) {
        for (int j = 0; j < height / blockSize; j++) {
            if (i == 0 || j == 0 || i == (width / blockSize) - 1 || j == (height / blockSize) - 1) {
                world->addCollidable(new sf::IntRect(i * blockSize, j * blockSize, blockSize, blockSize));
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

#include <SFML/Graphics.hpp>

#include <Skeleton/Application.h>
#include <Skeleton/Managers/StateManager.h>
#include <Skeleton/Managers/CacheSystem.h>
#include "SimpleMenu.h"

#include <memory>

#include <Skeleton/Util/FPSCounter.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "skeleton v.0.0.7" /*,sf::Style::Fullscreen*/);
    window.setFramerateLimit(0U);

    Application::init(&window);
    auto backgroundImage = sen::CacheSystem::getResource<sf::Texture>("Images/bg.jpeg");
    Application::setBackgroundImage(*backgroundImage);
    auto temp = std::make_unique<MenuState>(window);
    sen::StateManager::pushState(std::move(temp));
    Application::run();

    return 0;
}

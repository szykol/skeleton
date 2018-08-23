/**
    Source.cpp
    
    For testing purposes.

    @author: szykol
    @version 0.0.4
*/
#include "vendor/nlohmann/json.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <memory>

#include "Managers/ResourceManager.h"
#include "GUI/GUIheaders.h"
#include "States/StateHeaders.h"
#include "Util/UtilHeaders.h"
#include "GUI/Button.h"
#include "Managers/Cacheable.h"
#include "Managers/SFMLCacheSystem.h"
#include "Managers/ResourceManager.h"

int main()
{
    using Manager = sen::ResourceManager;
    sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.4");
    const sf::Vector2f centerPos(window.getSize().x / 2.f, window.getSize().y / 2.f);

	sen::StateManager::pushState<sen::TestState>(window);

    Manager::getAudioProvider().playSound("Sounds/dobrze.wav");

    sf::Clock timer;
    sf::Clock timer2;
    sen::FPSCounter counter;

    window.setFramerateLimit(60U);
    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
            if (evnt.type == sf::Event::KeyPressed)
            {
                if (evnt.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            if (evnt.type == sf::Event::TextEntered)
            {
                sen::InputController::handleInput(evnt);
            }
        }

        window.clear(sf::Color::Black);

        float deltaTime = timer.restart().asSeconds();
        counter.update(deltaTime);
        counter.render(window);

        sen::InputController::render(window);

        if(timer2.getElapsedTime().asSeconds() > 5.f)
        {
            Manager::getAudioProvider().playSound("Sounds/dobrze.wav");
            timer2.restart();
        }

		sen::StateManager::run(window);
        window.display();
    }
    return 0;
}
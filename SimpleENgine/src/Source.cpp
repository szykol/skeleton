/**
    Source.cpp
    
    For testing purposes.

    @author: szykol
    @version 0.0.3
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

int main()
{	
    sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.3");
    window.setFramerateLimit(60U);
    const sf::Vector2f centerPos(window.getSize().x / 2.f, window.getSize().y / 2.f);

	sen::StateManager::pushState<sen::TestState>(window);

    sf::Clock timer;
    sen::FPSCounter counter;

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

        sen::StateManager::run(window);

        window.display();
    }
    return 0;
}
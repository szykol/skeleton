/**
    Source.cpp
    
    For testing purposes.

    @author: szykol
    @version 0.0.5
*/
#include "vendor/nlohmann/json.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "Managers/ManagerHeaders.h"
#include "GUI/GUIheaders.h"
#include "States/StateHeaders.h"
#include "Util/UtilHeaders.h"


int main()
{
    using Manager = sen::ResourceManager;
	using AC = sen::AnimationController;

    sf::RenderWindow window(sf::VideoMode(1200, 800), "sen v.0.0.5");

    const sf::Vector2f centerPos(window.getSize().x / 2.f, window.getSize().y / 2.f);

	sen::StateManager::pushState<sen::TestState>(window);

    //Manager::getAudioProvider().playSound("Sounds/dobrze.wav");

    sf::Clock timer;
    sen::FPSCounter counter;

	sen::Text test("Test");

	//window.setFramerateLimit(60);
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

		sen::InputController::update(deltaTime);
        sen::InputController::render(window);
		
		AC::update(deltaTime);

		sen::StateManager::update(deltaTime, window);

        window.display();
    }
    return 0;
}
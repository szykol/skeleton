/**
    Source.cpp
    
    For testing purposes.

    @author: szykol
    @version 0.0.4
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

    sf::RenderWindow window(sf::VideoMode(1200, 800), "sen v.0.0.4");

    const sf::Vector2f centerPos(window.getSize().x / 2.f, window.getSize().y / 2.f);

	sen::StateManager::pushState<sen::TestState>(window);

    //Manager::getAudioProvider().playSound("Sounds/dobrze.wav");

    sf::Clock timer;
    sf::Clock timer2;
    sen::FPSCounter counter;

	sen::Text text("Welcome");
	sen::Text text2 = text;

	//AC::add(&text, centerPos, 1.f);
	//AC::add(&text2, sf::Vector2f(700.f, 200.f), 1.f);

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
		
		AC::update();
		/*text.render(window);
		text2.render(window);
*/
		sen::StateManager::run(window);

        window.display();
    }
    return 0;
}
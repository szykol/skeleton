/**
	Source.cpp
	
	For testing purposes.

	@author: szykol
	@version 0.0.3
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Managers/ResourceManager.h"
#include "UI/UIheaders.h"
#include "States/StateHeaders.h"
#include <functional>
#include <vector>
#include "Util/FPSCounter.h"
#include "Util/InputController.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.3");
	window.setFramerateLimit(60U);
	const sf::Vector2f centerPos(window.getSize().x / 2.f, window.getSize().y / 2.f);

	//sen::StateManager::pushState(new sen::TestState(window));

	/*sen::Text tekst("Temp");
	tekst.setPosition(centerPos);*/


	sf::Clock timer;
	sen::FPSCounter counter;

	sen::InputBox ib("Say something");
	ib.setPosition(centerPos);

	while (window.isOpen())
	{

		// turning of the pollevent section as its needed 
		// in the inputbox functionality - this will not
		// be the case as it's needed here.

		// managing input in the inputbox and inputcontroller
		// will be reworked soon. Current solution doesn't work
		// and will be erased in the next commit

		//sf::Event evnt;
		//while (window.pollEvent(evnt))
		//{
		//	if (evnt.type == sf::Event::Closed)
		//		window.close();
		//	if (evnt.type == sf::Event::KeyPressed)
		//	{
		//		if (evnt.key.code == sf::Keyboard::Escape)
		//			window.close();
		//	}
		//	/*if (evnt.type == sf::Event::TextEntered)
		//	{
		//		ic.handleInput(evnt);
		//	}*/
		//}

		window.clear(sf::Color::Black);

		float deltaTime = timer.restart().asSeconds();
		counter.update(deltaTime);
		counter.render(window);

		//ic.render(window);

		ib.update(window);
		ib.render(window);

		/*sen::StateManager::run(window);*/

		window.display();

	}
	return 0;
}
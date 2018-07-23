/**
	Source.cpp
	
	For testing purposes.

	@author: szykol
	@version 0.0.2
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Managers/ResourceManager.h"
#include "UIheaders.h"
#include <functional>
#include <vector>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.2");
	window.setFramerateLimit(20);

	sen::ButtonStaticCallback buttonStatic("Hello");
	buttonStatic.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
	
	sen::Button button("Hello");
	button.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f - 60.f));

	sen::ButtonCallback buttonCallback("Hello");
	buttonCallback.setPosition(sf::Vector2f(window.getSize().x / 2.f , window.getSize().y / 2.f + 60.f));

	std::vector<sen::Button*> buttons;

	buttons.push_back(&buttonStatic);
	buttons.push_back(&button);
	buttons.push_back(&buttonCallback);

	for (auto &b : buttons)
	{

		b->setOnClickCalback([&window] {
			window.close();
		});
	}

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);
		
		for (auto &b : buttons)
		{
			b->update(window);
			b->render(window);
		}

		window.display();
	}
	return 0;
}
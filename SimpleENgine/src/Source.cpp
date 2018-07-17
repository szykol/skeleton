#include <iostream>
#include <SFML/Graphics.hpp>
#include "text.h"
#include <unordered_map>

#include "Managers/ResourceManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.1");


	sen::text tekst("Dziendoberek");
	tekst.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
	
	sf::Sprite jakisSprajt(ResourceManager::get("xddd"));

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		tekst.draw(window);
		window.draw(jakisSprajt);
		window.display();
	}

	return 0;
}
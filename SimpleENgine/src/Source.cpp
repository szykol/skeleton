#include <iostream>
#include <SFML/Graphics.hpp>
#include "text.h"
#include <unordered_map>
#include "TestMap.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.1");
	sf::Font font;
	font.loadFromFile("Fonts/Roboto.ttf");

	FontMap fMap;
	sen::text tekst("Dziendoberek", fMap["Roboto"]);
	tekst.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
	


	


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
		window.display();
	}

	return 0;
}
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
#include "UI/_test_CallbackTextButton.h"
#include <functional>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.2");
	window.setFramerateLimit(20);
	sen::TextBox test("Dzien dobry");

	test.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
	
	sen::TextButton przycisk("klik");
	przycisk.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
	przycisk.setOnClickFunction([&window] {
		window.close();
	});

	sen::CallbackTextButton testCallback("callback");
	testCallback.setPosition(przycisk.getPosition());

	
	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		//test.render(window);
		/*przycisk.update(window);
		przycisk.render(window);*/
		testCallback.update(window);
		testCallback.render(window);
		window.display();
	}

	return 0;
}
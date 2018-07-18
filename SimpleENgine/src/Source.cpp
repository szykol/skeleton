#include <iostream>
#include <SFML/Graphics.hpp>
#include "text.h"
#include <unordered_map>
#include "Managers/ResourceManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.1");
	window.setFramerateLimit(20);
	sen::text tekst("Dziendoberek");
	tekst.setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
	window.setMouseCursorVisible(false);

	sf::Texture blurred = ResourceManager::get("background.jpeg");
	sf::Sprite sprajtBlurred(blurred);
	//sprajtNormal.move(sf::Vector2f(300.f, 300.f));
	sf::Shader shader;
	
	if (!shader.loadFromFile("Shaders/blur.frag", sf::Shader::Fragment))
		std::cout << "Couldn't load the shader" << std::endl;
	

	if (!shader.isAvailable())
	{
		std::cout << "Shader not available!" << std::endl;
	}

	float temp = 0.0f;
	shader.setUniform("blur_radius", temp);
	//shader.setUniform("blurSize", 0.0f);
	shader.setUniform("texture", blurred);
	sprajtBlurred.setTexture(blurred);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			temp += 0.001;
			shader.setUniform("blur_radius", temp);
			std::cout << temp << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			temp = 0.0f;
			shader.setUniform("blur_radius", temp);
			std::cout << temp << std::endl;
		}

		window.clear(sf::Color::Black);
		tekst.draw(window);
		window.draw(sprajtBlurred, &shader);
		window.display();
	}

	return 0;
}
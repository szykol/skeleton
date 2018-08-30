#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Application : public sf::NonCopyable
{
private:
	static sf::RenderWindow* s_window;
	static unsigned int s_frameRate;
	static sf::Clock s_timer;
	static sf::Vector2u s_initialRes;
public:
	static void init(sf::RenderWindow* window);
    static void run();
	static sf::RenderWindow& getWindow() { return *s_window; }
	static const sf::Vector2u& getInitialResolution() { return s_initialRes; }
	static sf::Vector2f getMappedMousePosition();
};

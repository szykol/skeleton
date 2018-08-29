#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Application : public sf::NonCopyable
{
private:
	static sf::RenderWindow* m_window;
	static unsigned int m_frameRate;
	static sf::Clock m_timer;
public:
	static void init(sf::RenderWindow* window);
    static void run();
	static sf::RenderWindow& getWindow() { return *m_window; }
};

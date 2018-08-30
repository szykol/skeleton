#include <SFML/Graphics.hpp>

#include "Application.h"
#include "Managers/StateManager.h"
#include "States/TestState.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "skeleton v.0.0.6"/*,sf::Style::Fullscreen*/);
	window.setFramerateLimit(0U);

	Application::init(&window);
	sen::StateManager::pushState<sen::TestState>(window);
	Application::run();
    
    return 0;
}
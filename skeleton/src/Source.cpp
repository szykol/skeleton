/**
    Source.cpp
    
    For testing purposes.

    @author: szykol
    @version 0.0.6
*/
#include "vendor/nlohmann/json.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "Managers/ManagerHeaders.h"
#include "GUI/GUIheaders.h"
#include "States/StateHeaders.h"
#include "Util/UtilHeaders.h"

#include "Application.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "skeleton v.0.0.6"/*,sf::Style::Fullscreen*/);
	window.setFramerateLimit(0U);
	//...
	Application::init(&window);

	sen::StateManager::pushState<sen::TestState>(window);

	Application::run();
    
    return 0;
}
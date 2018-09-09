#include <SFML/Graphics.hpp>

#include "Application.h"
#include "Managers/StateManager.h"
#include "States/FrameworkSplashScreen.h"
#include "States/TestState.h"
#include "Managers/CacheSystem.h"
#include "GUI/Transformable.h"
#include "GUI/Text.h"

#include <memory>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "skeleton v.0.0.6"/*,sf::Style::Fullscreen*/);
	window.setFramerateLimit(0U);
	
	sen::Text t("DzienDobry");
	t.setPosition(100.f, 200.f, 2.f);

	Application::init(&window);
	auto temp = std::make_unique<sen::FrameworkSplashScreen>();
	sen::StateManager::pushState(std::move(temp));
	//sen::StateManager::pushState<sen::FrameworkSplashScreen>();
	Application::run();
    
    return 0;
}
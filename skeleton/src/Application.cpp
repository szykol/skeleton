#include "Application.h"

#include "Managers/ManagerHeaders.h"
#include "States/StateHeaders.h"
#include "Util/Animation.h"

sf::RenderWindow* Application::s_window;
unsigned int Application::s_frameRate;
sf::Clock Application::s_timer;
sf::Vector2u Application::s_initialRes;

void Application::init(sf::RenderWindow * window)
{
	s_window = window;
	s_timer.restart();

	s_initialRes = s_window->getSize();
}

void Application::run()
{/*
	{
		sf::Vector2f centerPos(s_window->getSize().x / 2.f, s_window->getSize().y / 2.f);
		sf::View view(centerPos, sf::Vector2f(s_window->getSize().x, s_window->getSize().y));
		s_window->setView(view);
	}*/
	while (s_window->isOpen())
	{
		sf::Event evnt;
		while (s_window->pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				s_window->close();
			if (evnt.type == sf::Event::KeyPressed)
			{
				if (evnt.key.code == sf::Keyboard::Escape)
					s_window->close();
			}
			if (evnt.type == sf::Event::TextEntered)
			{
				sen::InputController::handleInput(evnt);
			}

			sen::StateManager::handleEvent(evnt);
		}
		s_window->clear(sf::Color::Black);
		float deltaTime = s_timer.restart().asSeconds();

		sen::InputController::update(deltaTime);
		sen::AnimationController::update(deltaTime);
		sen::InputController::render(*s_window);
		sen::StateManager::update(deltaTime, *s_window);
		s_window->display();
	}
}

sf::Vector2f Application::getMappedMousePosition()
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*s_window);
	sf::Vector2f worldPos = s_window->mapPixelToCoords(pixelPos);
	return worldPos;
}


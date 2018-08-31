#include "Application.h"

#include "Managers/InputController.h"
#include "Managers/StateManager.h"
#include "Managers/AnimationController.h"

sf::RenderWindow* Application::s_window;
unsigned int Application::s_frameRate;
sf::Clock Application::s_timer;
sf::Vector2u Application::s_initialWindowSize;
sf::RectangleShape* Application::s_background = nullptr;

void Application::init(sf::RenderWindow * window)
{
	s_window = window;
	s_timer.restart();

	s_initialWindowSize = s_window->getSize();
}

void Application::run()
{
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
		if (s_background)
			s_window->draw(*s_background);

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

void Application::setBackgroundImage(const sf::Texture & image)
{
	if (!s_background)
	{
		s_background = new sf::RectangleShape();
		s_background->setSize((sf::Vector2f)s_initialWindowSize);
		s_background->setTexture(&image);
	}
}

void Application::disableBackgroundImage()
{
	if (s_background)
	{
		delete s_background;
		s_background = nullptr;
	}
}


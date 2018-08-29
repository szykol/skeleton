#include "Application.h"

#include "Managers/ManagerHeaders.h"
#include "States/StateHeaders.h"
#include "Util/Animation.h"

sf::RenderWindow* Application::m_window;
unsigned int Application::m_frameRate;
sf::Clock Application::m_timer;

void Application::init(sf::RenderWindow * window)
{
	m_window = window;
	m_timer.restart();
}

void Application::run()
{
	auto texture = sen::ResourceManager::getTexture("Images/zombie.png");
	sen::Animation anim(texture, { 6,1 }, 0.2f);
	//anim.setFlippedFrame();
	//anim.setRow(3);
	sf::Sprite sprajt(texture);

	while (m_window->isOpen())
	{
		sf::Event evnt;
		while (m_window->pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				m_window->close();
			if (evnt.type == sf::Event::KeyPressed)
			{
				if (evnt.key.code == sf::Keyboard::Escape)
					m_window->close();
			}
			if (evnt.type == sf::Event::TextEntered)
			{
				sen::InputController::handleInput(evnt);
			}
			sen::StateManager::handleEvent(evnt);
		}
		m_window->clear(sf::Color::Black);
		float deltaTime = m_timer.restart().asSeconds();

		anim.update(deltaTime);
		sprajt.setTextureRect(anim.getTextureRect());
		m_window->draw(sprajt);

		sen::InputController::update(deltaTime);
		sen::AnimationController::update(deltaTime);
		sen::InputController::render(*m_window);
		sen::StateManager::update(deltaTime, *m_window);
		m_window->display();
	}
}

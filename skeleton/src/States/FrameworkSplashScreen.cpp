#include "FrameworkSplashScreen.h"

#include "../Application.h"
#include "../Managers/StateManager.h"
#include "TestState.h"

namespace sen {
	FrameworkSplashScreen::FrameworkSplashScreen()
		: m_mainMessage("SKELETON"),
		  m_info("Press any key to continue...")
	{
		sf::Vector2f initSize = (sf::Vector2f)Application::getInitialWindowSize();
		m_mainMessage.setPosition(initSize / 2.f);
		m_info.setPosition({ initSize.x / 2.f, initSize.y - 100 });
		m_info.setCharacterSize(24U);
	}
	void FrameworkSplashScreen::update(float deltaTime, sf::RenderWindow & window)
	{
		m_time += deltaTime;
		if (m_time > m_delay)
		{
			StateManager::pushState<TestState>(Application::getWindow());
			StateManager::clearStates();
		}
	}
	void FrameworkSplashScreen::handleEvents(sf::Event & evnt)
	{
		if(evnt.type == sf::Event::TextEntered)
		{
			StateManager::pushState<TestState>(Application::getWindow());
			StateManager::clearStates();
		}
	}
	void FrameworkSplashScreen::render(sf::RenderTarget & target)
	{
		m_mainMessage.render(target);
		m_info.render(target);
	}
}
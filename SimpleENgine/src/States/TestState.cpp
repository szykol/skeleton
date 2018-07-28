#include "TestState.h"
#include "StateManager.h"

namespace sen {
	TestState::TestState(sf::RenderWindow & window)
		: m_infoButton("Test State")
	{
		m_infoButton.setPosition(
			sf::Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f + 100.f));

		m_infoButton.m_onHoverCallback = [](Button &button) {
			button.getTextObject().setString("Click me");
		};

		m_infoButton.m_onUnhoverCallback = [](Button &button) {
			button.getTextObject().setString("Test State");
		};

		m_infoButton.m_callback = [] {
			sen::StateManager::popState();
		};
	}
	void TestState::update(sf::RenderWindow & window)
	{
		m_infoButton.update(window);
	}
	void TestState::input(sf::RenderWindow & window)
	{

	}
	void TestState::render(sf::RenderTarget & target)
	{
		m_infoButton.render(target);
	}
}
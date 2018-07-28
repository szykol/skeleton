/**
	Source.cpp
	
	For testing purposes.

	@author: szykol
	@version 0.0.3
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Managers/ResourceManager.h"
#include "UIheaders.h"
#include "States/StateHeaders.h"
#include <functional>
#include <vector>

class TempState : public sen::State
{
private:
	sen::ButtonCallback m_infoButton;
public:
	TempState(sf::RenderWindow &window) :m_infoButton("Hover over me") {
		m_infoButton.m_onHoverCallback = [](sen::Button &button) {
			button.getTextObject().setString("Spawn TestState");
		};

		m_infoButton.m_onUnhoverCallback = [](sen::Button &button) {
			button.getTextObject().setString("Hover over me");
		};

		m_infoButton.m_callback = [&window] {
			sen::StateManager::pushState(new sen::TestState(window));
		};
		m_infoButton.setPosition(sf::Vector2f(window.getSize().x / 2.f, 
									window.getSize().y / 2.f - 100.f));
	}
	virtual void update(sf::RenderWindow &window) override {
		m_infoButton.update(window);
	}
	virtual void input(sf::RenderWindow &window)  override {
	}
	virtual void render(sf::RenderTarget &target) override {
		m_infoButton.render(target);
	}

	virtual ~TempState() = default;
};



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sen v.0.0.3");
	const sf::Vector2f centerPos(window.getSize().x / 2.f, window.getSize().y / 2.f);

	sen::StateManager::pushState(new TempState(window));

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);

		sen::StateManager::run(window);

		window.display();

	}
	return 0;
}
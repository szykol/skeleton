#pragma once

#include "State.h"
#include "../GUI/Text.h"

namespace sen {
	class FrameworkSplashScreen : public State
	{
		float m_delay = 5.f;
		float m_time = 0.f;
		Text m_mainMessage;
		Text m_info;
	public:
		FrameworkSplashScreen();
		virtual void update(float deltaTime, sf::RenderWindow& window) override;
		virtual void handleEvents(sf::Event& evnt) override;
		virtual void render(sf::RenderTarget& target) override;

		~FrameworkSplashScreen() = default;
	};
}
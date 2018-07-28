#pragma once

#include "State.h"
#include "../UIheaders.h"

namespace sen {
	class TestState : public State
	{
	private:
		ButtonCallback m_infoButton;
	public:
		TestState(sf::RenderWindow &window);

		virtual void update(sf::RenderWindow &window) override;
		virtual void input(sf::RenderWindow &window)  override;
		virtual void render(sf::RenderTarget &target) override;

		virtual ~TestState() = default;
	};
}
#pragma once

#include <vector>
#include "Button.h"

namespace sen {
	class ButtonController
	{
		std::vector<Button*> buttons;
		int activeIndex = 0;
		sf::Clock timer;
	public:
		ButtonController() = default;
		ButtonController(const std::vector<Button*> &buttons);
		void update(sf::RenderWindow &window);
		void render(sf::RenderTarget &target);
	private:
		void placeButtons();
	};
}
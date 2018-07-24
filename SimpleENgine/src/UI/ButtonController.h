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
		explicit ButtonController(const std::vector<Button*> &buttons);
		ButtonController(const std::vector<Button*> buttons, const sf::RenderWindow &window);
		void update(sf::RenderWindow &window);
		void render(sf::RenderTarget &target);
		void placeButtons(const sf::RenderWindow &window);
	};
}
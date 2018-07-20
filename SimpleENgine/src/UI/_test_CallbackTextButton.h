#pragma once

#include "Textbox.h"
#include <functional>

namespace sen {
	/**
		It's for testing purposes only and probably will be deleted soon
	*/
	class CallbackTextButton : public TextBox
	{
	public:
		std::function<void(CallbackTextButton &)> onHover;
		std::function<void(CallbackTextButton &)> onUnhover;
		std::function<void(CallbackTextButton &)> onClick;

		CallbackTextButton(const std::string &string);
		void update(const sf::RenderWindow &window);
		bool mouseOver(const sf::RenderWindow &window);
		void render(sf::RenderTarget &target) { TextBox::render(target); }
	};
}
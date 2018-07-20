#pragma once

#include "Textbox.h"
#include "InterfaceButton.h"

namespace sen {
	class TextButton : public TextBox, public InterfaceButton
	{
	protected:
		sf::Vector2f originalSize;
		sf::Color originalColor;
		unsigned int originalCharacterSize;
	public:
		TextButton(const std::string &string);
		void render(sf::RenderTarget &target);
		virtual void update(const sf::RenderWindow &window)		override;
	protected:
		virtual void onHover()									override;
		virtual void onUnhover()								override;
		virtual void onClick()									override;
		virtual void onUnClick()								override;
		virtual bool mouseOver(const sf::RenderWindow &window)	override;
	};
}
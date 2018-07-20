#pragma once

#include "Textbox.h"
#include "InterfaceButton.h"

namespace sen {
	/**
		Extends functionality of TextBox and InterfaceButton
		overrides all methods provided in InterfaceButton
	*/
	class TextButton : public TextBox, public InterfaceButton
	{
	protected:
		sf::Vector2f originalSize;
		sf::Color originalColor;
		unsigned int originalCharacterSize;
	public:
		/**
			Calls TextBox constructor which bassicly sets the Box around the text

			@param string String that will be displayed inside of button
		*/
		TextButton(const std::string &string);
		/**
			Draws the button on the target
		*/
		void render(sf::RenderTarget &target);
		/**
			Overriden from InterfaceButton.
			Contains all logic that button needs to work properly

			@param window Window is needed to tell the position of Mouse
		*/
		virtual void update(const sf::RenderWindow &window)		override;
	protected:
		/**
			Overriden from InterfaceButton.
			Changes the button on mouse hover
		*/
		virtual void onHover()									override;
		/**
			Overriden from InterfaceButton.
			Changes the button on mouse leaving the button
		*/
		virtual void onUnhover()								override;
		/**
			Overriden from InterfaceButton.
			Changes the button on mouse click
		*/
		virtual void onClick()									override;
		/**
			Overriden from InterfaceButton.
			Checks if mouse hovers over the button

			@param window Window is needed to tell the position of Mouse
		*/
		virtual bool mouseOver(const sf::RenderWindow &window)	override;
	};
}
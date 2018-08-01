#pragma once

#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include <functional>

typedef std::function<void(void)> onClickCallback;

namespace sen {
	/**
	 *	Provides an interface for button functionality.
	 *	Those virtual voids need to be overriden in order to specify how button behaves. 
	 *	Provides callback function that's being called whenever user presses the button
	 */
	class Button : public TextBox
	{
	protected:
		sf::Clock m_timer;
		bool clickable = false;
	public:
		onClickCallback m_callback;
		explicit Button(const sf::String &string) : TextBox(string) {}
		/**
		 *	This should change the button on mouse hover
		 */
		virtual void onHover();
		/**
		 *	This should change the button on mouse leaving the button
		 */
		virtual void onUnhover();
		/**
		 *	This should change the button on mouse click
		 */
		virtual void onClick();
		/**
		 *	This should be whole logic of the button, checks if mouse hovers over the button,
		 *  if button is clicked etc
		 *
		 *	@param window Window needed to get the position of Mouse
		 */
		virtual void update(sf::RenderWindow &window);
		/**
		 *	Checks if a Mouse hovers over the button
		 */
		virtual bool mouseOver(const sf::RenderWindow &window);
		/**
		 *	Sets a callback function called on mouse click
		 */
		void setOnClickCalback(const onClickCallback &callback) { m_callback = callback; }
		virtual ~Button() = default;
	};
	/*void standardOnHover(Button &button);
	void standardOnUnhover(Button &button);
	void standardOnClick(Button &button);*/
}
#pragma once

#include <SFML/Graphics.hpp>
#include "Textbox.h"
#include <functional>

typedef std::function<void(void)> onClickCallback;

namespace sen {
	/**
		Abstract class. Provides an interface for button functionality.
		Those virtual voids need to be overriden in order to specify how button behaves. 
		Provides callback function that's being called wherever user presses the button
	*/
	class Button : public TextBox
	{
	protected:
		sf::Clock timer;
		bool clickable = true;
		onClickCallback callback;
	public:
		Button(const std::string &string) : TextBox(string) {}
		/**
			This should change the button on mouse hover
		*/
		virtual void onHover();
		/**
			This should change the button on mouse leaving the button
		*/
		virtual void onUnhover();
		/**
			This should change the button on mouse click
		*/
		virtual void onClick();
		/**
			This should be whole logic of the button, checks if mouse hovers over the button, if button is clicked etc

			@param window Window needed to get the position of Mouse
		*/
		virtual void update(const sf::RenderWindow &window);
		/**
			Checks if a Mouse hovers over the button
		*/
		virtual bool mouseOver(const sf::RenderWindow &window);
		/**
			Sets a callback function called on mouse click
		*/
		void setOnClickCalback(const onClickCallback &callback) { this->callback = callback; }
	};
	/*void standardOnHover(InterfaceButton &button);
	void standardOnUnhover(InterfaceButton &button);
	void standardOnClick(InterfaceButton &button);*/
}
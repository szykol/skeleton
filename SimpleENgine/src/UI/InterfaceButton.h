#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

typedef std::function<void(void)> Callback;

namespace sen {
	/**
		Abstract class. Provides an interface for button functionality.
		Those virtual voids need to be overriden in order to specify how button behaves. 
		Provides callback function that's being called wherever user presses the button
	*/
	class InterfaceButton
	{
	protected:
		sf::Clock timer;
		bool clickable = true;
		Callback onClickFunc;
	public:
		/**
			This should be whole logic of the button, checks if mouse hovers over the button, if button is clicked etc

			@param window Window needed to get the position of Mouse
		*/
		virtual void update(const sf::RenderWindow &window) = 0;
	protected:
		/**
			This should change the button on mouse hover
		*/
		virtual void onHover() = 0;
		/**
			This should change the button on mouse leaving the button
		*/
		virtual void onUnhover() = 0;
		/**
			This should change the button on mouse click
		*/
		virtual void onClick() = 0;
		/**
			Checks if a Mouse hovers over the button
		*/
		virtual bool mouseOver(const sf::RenderWindow &window) = 0;
	public:
		/**
			Sets a callback function called on mouse click
		*/
		void setOnClickFunction(const Callback &func) { onClickFunc = func; }
	};
}
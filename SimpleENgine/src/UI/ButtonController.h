#pragma once

#include <vector>
#include "Button.h"

namespace sen {
	/**
		All the buttons you pass to the controller will be
		updated and rendered. Additionaly controller has built 
		in logic that lets the user navigate through all of these
		buttons. It should be used in all sorts of menus.
		It can place all buttons evenly on the screen aswell as 
		set the same size for all of them.
		You will be able to pass the function to execute on each one
		of buttons.
	*/
	class ButtonController
	{
		bool m_nonStandardPosition = false;
		std::vector<Button*> m_buttons;
		int m_activeIndex = 0;
		sf::Clock m_timer;
		bool m_canClick = false;
	public:
		/**
			Default constructor of the controller.
		*/
		ButtonController() = default;
		/**
			Constructor that takes the vector of button pointers
			and makes a copy.

			@param buttons A vector of button pointers
		*/
		explicit ButtonController(const std::vector<Button*> &buttons);
		/**
			Constructor that takes the vector of button pointers
			and makes a copy. It places all buttons evenly on the
			screen.
			
			@param buttons A vector of button pointers
			@param window Window is needed for placing the buttons
		*/
		ButtonController(const std::vector<Button*> buttons, const sf::RenderWindow &window);
		/**
			Adds the button pointer to the vector

			@param button Button pointer wich will be added to the vector
		*/
		void addButtons(Button *button);
		/**
			Pass all buttons with single function call
		*/
		template<typename... Args>
		void addButtons(Button *button, Args... args)
		{
			m_buttons.push_back(button);

			addButtons(args...);
		}
		/**
			Removes last added button 
		*/
		void removeButton();
		/**
			Contains all the logic needed to navigate through menu.

			@param window Window needed to get the mouse position.
		*/
		void update(sf::RenderWindow &window);
		/**
			Renders all buttons.

			@param target Target to render on.
		*/
		void render(sf::RenderTarget &target);
		/**
			Places the buttons evenly on the screen.

			@param window Window needed to get it's size.
			@param gap Gap between buttons
		*/
		void placeButtons(const sf::RenderWindow &window, float gap = 20.f);
		/**
			Sets the X position of all buttons.

			@param x X position.
		*/
		void setPositionX(float x);
		/**
			Sets the same size for all buttons.

			@param size New size
		*/
		void setButtonFixedSize(const sf::Vector2f &size);
		/**
			Performs an specified action on each button.

			@param function Function that does something with button and
				   takes a button pointer as a parameter
		*/
		void map(const std::function<void(Button*)> &function);
		/**
			If using heap allocated buttons this method will 
			free up memory used by them.
		*/
		void freeMemory();
	};
}
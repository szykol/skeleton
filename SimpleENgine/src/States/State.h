#pragma once

#include <SFML/Graphics.hpp>

namespace sen {
	/**
	 * Interface for all state classes. It is made
	 * for StateManager class which works with
	 * State pointers.
	 * There are 3 methods that need to be overriden.
	 */
	class State : sf::NonCopyable
	{
	public:
		State() = default;
		/**
		 * Needs to be overriden. Contains all logic 
		 * needed to update the state
		 * @param window Window
	 	 */
		virtual void update(sf::RenderWindow &window) = 0;
	    /** 
          * @brief  Method that handles events that have occured
		  * in the window
          * @note   This method needs to be overriden.
          * @param  &evnt: Event from poll event method 
          */
		virtual void handleEvents(sf::Event &evnt) = 0;
		/**
		 * Needs to be overriden. Renders all entities.
	     * 
		 * @param target Target to draw on
		 */
		virtual void render(sf::RenderTarget &target) = 0;
		/**
		 * Needs to be overriden. Contains all logic
		 * needed to controll the input
		 * 
		 * @param window Window
		 */
		virtual void input(sf::RenderWindow &window) = 0;
		virtual ~State() = default;
	};
}
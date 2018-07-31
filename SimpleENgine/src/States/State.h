#pragma once

#include <SFML/Graphics.hpp>

namespace sen {
	/**
		Interface for all state classes. It is made
		for StateManager class which works with
		State pointers.
		There are 3 methods that need to be overriden.
	*/
	class State : sf::NonCopyable
	{
	public:
		State() = default;
		/**
			Needs to be overriden. Contains all logic 
			needed to update the state

			@window Window
		*/
		virtual void update(sf::RenderWindow &window) = 0;
		/**
			Needs to be overriden. Renders all entities.

			@target Target to draw on
		*/
		virtual void render(sf::RenderTarget &target) = 0;
		/**
			Needs to be overriden. Contains all logic
			needed to controll the input

			@window Window
		*/
		virtual void input(sf::RenderWindow &window) = 0;
		virtual ~State() = default;
	};
}
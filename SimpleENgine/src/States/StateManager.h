#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "State.h"

namespace sen {
	/**
	 *	Basic state manager. Works with classes 
	 *	that derive from State class.
     *
	 *	Updates current state
     *
	 *	Lets you push new states - it stops updating
	 *	current state and switches to new one.
     *
	 *	Lets you pop states - it stops updating
	 *	current state, delets it and switches to
	 *	the previous one
	 */
	class StateManager : sf::NonCopyable
	{
	private:
		static std::vector<State*> m_states;
		static State* m_currentState;
		static State* m_awaitState;
		static bool m_wannaPop;
	public:
		StateManager() = default;
		/**
		 *	Lets you push new state - it stops updating
		 *	current state and switches to new one.
		 *
		 *	@param newState New state to push
		 */
		static void pushState(State* newState);
		/**
		 *  Lets you pop states - it stops updating
		 *	current state, delets it and switches to
		 *	the previous one
		 */
		static void popState();
		/**
		 *	Basically updates current state.
		 *
		 *	@param window Window is needed for
		 *	       current state
		 */
		static void run(sf::RenderWindow &window);
		~StateManager();
	};
}
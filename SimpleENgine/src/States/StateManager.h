#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "State.h"

namespace sen {
	class StateManager : sf::NonCopyable
	{
	private:
		static std::vector<State*> m_states;
		static State* m_currentState;
		static State* m_awaitState;
		static bool m_wannaPop;
	public:
		StateManager() = default;
		static void pushState(State* newState);
		static void popState();
		static void run(sf::RenderWindow &window);
		~StateManager();
	};
}
#include "StateManager.h"

namespace sen {
	std::vector<State*> StateManager::m_states;
	State* StateManager::m_currentState = nullptr;
	State* StateManager::m_awaitState = nullptr;
	bool StateManager::m_wannaPop = false;

	void StateManager::pushState(State * newState)
	{
		// mark the new state as awaiting state
		m_awaitState = newState;
	}
	void StateManager::popState()
	{
		m_wannaPop = true;
	}
	void StateManager::run(sf::RenderWindow & window)
	{
		// if there's awaiting state - make it 
		// current state. push the previous state
		// to the vector
		if (m_awaitState)
		{
			m_states.push_back(m_currentState);
			m_currentState = m_awaitState;
			m_awaitState = nullptr;
		}
		// if there's anything to update
		if (m_currentState)
		{
			m_currentState->input(window);
			m_currentState->update(window);
			m_currentState->render(window);
		}
		// if there's a state that need to be
		// popped, pop it
		if (m_wannaPop)
		{
			delete m_currentState;
			if (m_states.empty())
				m_currentState = nullptr;
			else
			{
				m_currentState = m_states.back();
				m_states.pop_back();
			}
			m_wannaPop = false;
		}
	}
	StateManager::~StateManager()
	{
		// free up the memory
		std::for_each(m_states.begin(), m_states.end(), [](State* state) {
			delete state;
		});
		if(m_currentState)
			delete m_currentState;
	}
}
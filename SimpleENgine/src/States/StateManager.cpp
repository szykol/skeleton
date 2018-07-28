#include "StateManager.h"

namespace sen {
	std::vector<State*> StateManager::m_states;
	State* StateManager::m_currentState = nullptr;
	State* StateManager::m_awaitState = nullptr;
	bool StateManager::m_wannaPop = false;

	void StateManager::pushState(State * newState)
	{
		m_awaitState = newState;
	}
	void StateManager::popState()
	{
		m_wannaPop = true;
	}
	void StateManager::run(sf::RenderWindow & window)
	{
		if (m_awaitState)
		{
			m_states.push_back(m_currentState);
			m_currentState = m_awaitState;
			m_awaitState = nullptr;
		}
		if (m_currentState)
		{
			m_currentState->input(window);
			m_currentState->update(window);
			m_currentState->render(window);
		}
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
		std::for_each(m_states.begin(), m_states.end(), [](State* state) {
			delete state;
		});
		if(m_currentState)
			delete m_currentState;
	}
}
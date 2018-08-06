#include "StateManager.h"

namespace sen {
    StatePointerVector StateManager::m_states;
    StatePointer StateManager::m_currentState;
    StatePointer StateManager::m_awaitState;  
    PopupPointer StateManager::m_popup;  
    bool StateManager::m_wannaPop = false;

    void StateManager::pushState(StatePointer& newState)
    {
        // mark the new state as awaiting state
        m_awaitState = newState;
    }
    void StateManager::pushState(StatePointer&& newState)
    {
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
            /*sf::Event evnt;
            while(window.pollEvent(evnt))
                m_currentState->handleEvents(evnt);*/

			// if doesn't have popup or if it has but it doesn't pause
			// state
			if (!m_popup || !m_popup->pausesState())
			{
				m_currentState->input(window);
				m_currentState->update(window);
			}
			m_currentState->render(window);
        }
        if(m_popup)
        {
            m_popup->update(window);
            m_popup->render(window);
            if(m_popup->hasResponse())
                m_popup = nullptr;
        }
        // if there's a state that need to be
        // popped, pop it
        if (m_wannaPop)
        {
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
    void StateManager::pushPopup(PopupPointer& popup)
    {
        if(m_popup) return;
        
		m_popup = popup;
    }
    StateManager::~StateManager()
    {
    }
}
#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "../GUI/Prompt.h"
#include "State.h"
#include "../GUI/Popup.h"

namespace sen {
	typedef std::shared_ptr<State> StatePointer;
	typedef std::vector<StatePointer> StatePointerVector;
	typedef std::shared_ptr<Prompt> PromptPointer;
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
		static StatePointerVector m_states;
		static StatePointer m_currentState;
		static StatePointer m_awaitState;
		static PromptPointer m_prompt;
		static Popup* m_popup; // stos popupow ? 
		static bool m_wannaPop;
		StateManager() = default;
	public:
		/**
		 *	Basically updates current state.
		 *
		 *	@param window Window is needed for
		 *	       current state
		 */
		static void run(sf::RenderWindow &window);
		/**
		 *	Lets you push a new state - it stops updating
		 *	current state and switches to a new one.
		 *
		 *	@param newState New state to push
		 */
		static void pushState(StatePointer& newState);
		/** 
		 * @brief  Lets you push a new state if its
		 * an R-value. 
		 * @note   
		 * @param  newState: R-value state shared pointer
		 * @retval None
		 */
		static void pushState(StatePointer&& newState);
		/** 
		 * @brief  Lets you pass all constructor arguments
		 * of a state, and creates a shared pointer.
		 * This takes care of creating shared_ptr which
		 * could be a little complicated
		 * @note   All you need to do is pass the arguments
		 * needed in the State constructor
		 * @param  args: 
		 * @retval None
		 */
		template<typename tState, typename... Args>
		static void pushState(Args&... args)
		{
			m_awaitState = std::make_shared<tState>(args...);
		}
		/**
		 *  Lets you pop states - it stops updating
		 *	current state, delets it and switches to
		 *	the previous one
		 */
		static void popState();
		static void pushPrompt(PromptPointer& Prompt);
		static void pushPopup(Popup* popup);
		~StateManager();
	};
}
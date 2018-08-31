#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "../GUI/Prompt.h"
#include "../States/State.h"
#include "../GUI/Popup.h"

namespace sen {
	using StatePointer = std::shared_ptr<State>;
	using StatePointerVector = std::vector<StatePointer>;
	using PromptPointer = std::shared_ptr<Prompt>;
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
		static bool m_backButton;
		static Button* m_back;
	public:
		/**
		 *	Basically updates current state.
		 *
		 *	@param window Window is needed for
		 *	       current state
		 */
		static void update(float deltaTime, sf::RenderWindow& window);
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
		/** 
		 * @brief  Lets you push a new prompt (if there isn't already pushed)
		 * @note   It uses shared_ptr because that way it allows
		 * you to manage prompts response, if a response is ready
		 * StateManager stops updating the prompt and set's its
		 * PromptPointer to null (but you can still do something with it)
		 * @param  Prompt: new Prompt
		 * @retval None
		 */
		static void pushPrompt(PromptPointer& Prompt);
		/** 
		 * @brief  Lets you push a new popup which is 
		 * a simple notification block
		 * @note   When it's duration passes it's immediately
		 * removed from memory (hence c-style pointer)
		 * @param  popup: new Popup to be displayed
		 * @retval None
		 */
		static void pushPopup(Popup* popup);
		/** 
		 * @brief  Checks if there is any popup
		 * maintained by the manager
		 */
		static bool maintainsPopup() { return (bool)m_popup; }
		/** 
		 * @brief  Removes the current popup
		 * @retval None
		 */
		static void popPopup();
		/** 
		 * @brief  calls the current state
		 * handleEvents method
		 * @param  evnt: evnt from pollEvent loop
		 */
		static void handleEvent(sf::Event& evnt);
		/** 
		 * @brief  Clears all the states that were 
		 * pushed before
		 * @param  clearCurrent: if true, also deletes the
		 * current state
		 * @retval None
		 */
		static void clearStates(bool clearCurrent = false);
		/**
		 * @brief  Lets you switch off/on the button that enables
		 * you to pop current state (go back to previous one)
		 * @note  Button is on by default
		 */
		static void switchBackButton(bool set) { m_backButton = set; }
	};
}
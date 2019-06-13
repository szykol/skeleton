#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "../GUI/Prompt.h"
#include "../States/State.h"
#include "../GUI/Popup.h"

namespace sen {
	using StatePointerVector = std::vector<std::unique_ptr<State>>;
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
		static std::unique_ptr<State> m_currentState, m_awaitState;
		static PromptPointer m_prompt;
		static bool m_wannaPop;
		static bool m_backButton;
		static std::unique_ptr<Popup> m_popup;
		static std::unique_ptr<Button> m_back;
	public:
		/**
		 *	Basically updates current state.
		 *
		 *	@param window Window is needed for
		 *	       current state
		 */
		static void update(float deltaTime, sf::RenderWindow& window);
		/** 
		 * @brief  Lets you push a new state. Other states are storeed
		 * to enable popping states
		 * @param  newState: pointer to the new state
		 * @retval None
		 */
		static void pushState(std::unique_ptr<State> newState);
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
		static void pushState(Args&&... args)
		{
			m_awaitState = std::make_unique<tState>(std::forward<Args>(args)...);
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
		* @param  popup: new Popup to be displayed
		* @retval None
		*/
		static void pushPopup(std::unique_ptr<Popup> popup);
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
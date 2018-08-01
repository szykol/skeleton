#pragma once

#include "State.h"
#include "../UI/UIheaders.h"

namespace sen {
	/**
	 *	Example state. Shows how you can work with
	 *	buttons callbacks and state manager.
	 *	It simply lets you push states and pop them.
	 */
	class TestState : public State
	{
	private:
		sen::ButtonController m_buttonController;
		sen::TextBox m_info;
		static unsigned int s_pushedStates;
	public:
		/**
		 *	Sets up buttons, button controller.
		 *
		 *	@param window Window needed for button controller
		 */
		TestState(sf::RenderWindow &window);
		/**
		 *	Updates button controller.
		 *	
		 *	@param window Window needed for button controller
		 */
		virtual void update(sf::RenderWindow &window) override;
		/** 
		 * @brief  Handles events that have occured in the window
		 * @note   This method overrides from State class
		 * which is a base class for States
		 * @param  &evnt: Event from the window
		 * @retval None
		 */
	    virtual void handleEvents(sf::Event &evnt) 	  override;
		/**
		 *	Handles input (nothing here)
         *
		 *	@param window
		 */
		virtual void input(sf::RenderWindow &window)  override;
		/**
		 *	Renders the state
         *
		 *	@target Target you want to draw on.
		 */
		virtual void render(sf::RenderTarget &target) override;
		virtual ~TestState();
	};
}
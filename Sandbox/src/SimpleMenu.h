#pragma once

#include <States/State.h>
#include <GUI/GUIheaders.h>
#include <memory>

/**
 *	Example state. Shows how you can work with
	*	buttons callbacks and state manager.
	*	It simply lets you push states and pop them.
	*/
class MenuState : public sen::State
{
private:
	sen::ButtonController m_buttonController;
	sen::TextBox m_info;
	std::shared_ptr<sen::Prompt> m_prompt;
	static unsigned int s_pushedStates;
public:
	/**
	 *	Sets up buttons, button controller.
		*
		*	@param window Window needed for button controller
		*/
	MenuState(sf::RenderWindow &window);
	/**
	 *	Updates button controller.
		*	
		*	@param window Window needed for button controller
		*/
	virtual void update(float deltaTime, sf::RenderWindow &window) override;
	/**
	 *	Renders the state
		*
		*	@target Target you want to draw on.
		*/
	virtual void render(sf::RenderTarget &target) override;
	virtual ~MenuState();

	MenuState(MenuState&&) = default;
	MenuState& operator=(MenuState&&) = default;
};
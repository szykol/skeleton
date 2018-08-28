#include "InputBox.h"

#include "../Managers/InputController.h"

namespace sen {
	InputBox::InputBox(const sf::String & placeholder)
		: m_placeholder(placeholder),
		  Button(placeholder), m_hasFocus(false)
	{
		Button::setFitTextSize(false);

		//default validation function checks if input
		//is less than 30 character long
		InputController::setValidateFunction(
			[](const sf::String& string) -> bool {
				return string.getSize() <= 30;
			}
		);
	}
	void InputBox::onHover()
	{
		if (!m_hasFocus)
			Button::onHover();
	}
	void InputBox::onUnhover()
	{
		// if it doesn't have focus: unbind the InputController
		// if user typed something display what he wrote
		// if input is empty show placeholder string instead.
		if (!m_hasFocus)
		{
			Button::onUnhover();
			if (m_message.getString().getSize() == 0)
				m_message.setString(m_placeholder);
			InputController::unbindText();
			Button::setOutlineThickness(-2.5f);
		}
	}
	void InputBox::onClick()
	{
		// toggle between focus
		if (!m_hasFocus)
			onFocus();
		else
		{
			m_hasFocus = false;
			onUnhover();
		}
		
	}
	void InputBox::onFocus()
	{
		// binds InputController
		InputController::bindText(m_message);
		m_hasFocus = true;
		Button::setOutlineThickness(-3.5);
		if (m_message.getString() == m_placeholder)
			m_message.setString("");
	}
	void InputBox::render(sf::RenderTarget & target)
	{
		Button::render(target);
		if(m_hasFocus)
			InputController::render(target);
	}
	const sf::String& InputBox::getString() const
	{
		return m_message.getString();
	}
	InputBox::~InputBox()
	{
		InputController::unbindText();
	}
}
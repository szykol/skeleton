#include "InputBox.h"

#include "../Util/InputController.h"

namespace sen {
	InputBox::InputBox(const sf::String & placeholder)
		: m_placeholder(placeholder),
		  Button(placeholder), m_hasFocus(false)
	{
		Button::setFitTextSize(false);
		InputController::setValidateFunction(
			[](const sf::String& string) -> bool {
				return string.getSize() <= 30;
			}
		);
	}
	void InputBox::update(sf::RenderWindow & window)
	{
		// create a cooldown to avoid calling the callback function every frame
		if (m_timer.getElapsedTime().asSeconds() > 0.5f
			&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			clickable = true;
			m_timer.restart();
		}

		if (mouseOver(window))
		{
			onHover();
			if (clickable && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				onClick();
				if (m_clickCallback)
					m_clickCallback();
				clickable = false;
			}
		}
		else
		{
			onUnhover();
		}
	}
	void InputBox::onHover()
	{
		if (!m_hasFocus)
			Button::onHover();
	}
	void InputBox::onUnhover()
	{
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
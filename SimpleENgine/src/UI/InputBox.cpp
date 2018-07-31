#include "InputBox.h"

namespace sen {
	InputBox::InputBox(const sf::String & placeholder)
		: m_ic(m_message), m_placeholder(placeholder),
		  Button(placeholder), m_hasFocus(false)
	{
		m_ic.setValidateFunction(
			[](const sf::String& string) -> bool {
				return string.getSize() <= 30;
			}
		);
	}
	void InputBox::update(sf::RenderWindow & window)
	{
		if (m_hasFocus)
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				if (evnt.type = sf::Event::TextEntered)
					m_ic.handleInput(evnt);
			}
		}
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
				if (m_callback)
					m_callback();
				clickable = false;
			}
		}
		else
			onUnhover();
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
		m_hasFocus = true;
		Button::setOutlineThickness(-3.5);
		if (m_message.getString() == m_placeholder)
			m_message.setString("");
	}
	void InputBox::render(sf::RenderTarget & target)
	{
		Button::render(target);
		if(m_hasFocus)
			m_ic.render(target);
	}
}
#include "Button.h"

namespace sen {
	void Button::onHover()
	{
		setFillColor(sf::Color(sf::Color(25, 25, 25, 50)));
		setOutlineColor(sf::Color(222, 222, 222, 240));
		m_message.setFillColor(getOutlineColor());
	}
	void Button::onUnhover()
	{
		setFillColor(sf::Color(25, 25, 25, 170));
		setOutlineColor(sf::Color(222, 222, 222, 170));
		m_message.setFillColor(Box::getOutlineColor());
	}
	void Button::onClick()
	{
		setOutlineColor(sf::Color(0, 198, 0, 190));
		m_message.setFillColor(Box::getOutlineColor());
	}
	void Button::update(const sf::RenderWindow & window)
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
				if (m_callback)
					m_callback();
				clickable = false;
			}
		}
		else
			onUnhover();




		//// if the button is clickable again..
		//if (clickable)
		//{
		//	// and mouse hovers over the button..
		//	if (mouseOver(window))
		//	{
		//		onHover();
		//		// and the button is pressed
		//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		//		{
		//			onClick();
		//			if (m_callback)
		//				m_callback();
		//			clickable = false;
		//		}
		//	}
		//	// or the mouse doesn't hover over
		//	else
		//	{
		//		onUnhover();
		//	}
		//}
	}
	bool Button::mouseOver(const sf::RenderWindow & window)
	{
		// get position of mouse
		const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		// return whether the mouse is in bounds of button
		return (getGlobalBounds().contains(mousePos));
	}
	/*void standardOnHover(Button & button)
	{
		button.setFillColor(sf::Color(25, 25, 25, 170));
		button.setOutlineColor(sf::Color(222, 222, 222, 170));
		button.getTextObject().setFillColor(button.getOutlineColor());
	}
	void standardOnUnhover(Button & button)
	{
		button.setFillColor(sf::Color(sf::Color(25, 25, 25, 50)));
		button.setOutlineColor(sf::Color(222, 222, 222, 240));
		button.getTextObject().setFillColor(button.getOutlineColor());
	}
	void standardOnClick(Button & button)
	{
		button.setOutlineColor(sf::Color(0, 198, 0, 190));
		button.getTextObject().setFillColor(button.getOutlineColor());
	}*/
}
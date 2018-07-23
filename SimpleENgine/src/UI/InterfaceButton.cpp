#include "InterfaceButton.h"

namespace sen {
	void Button::onHover()
	{
		this->setFillColor(sf::Color(25, 25, 25, 170));
		this->setOutlineColor(sf::Color(222, 222, 222, 170));
		this->message.setFillColor(Box::getOutlineColor());
	}
	void Button::onUnhover()
	{
		this->setFillColor(sf::Color(sf::Color(25, 25, 25, 50)));
		this->setOutlineColor(sf::Color(222, 222, 222, 240));
		this->message.setFillColor(this->getOutlineColor());
	}
	void Button::onClick()
	{
		this->setOutlineColor(sf::Color(0, 198, 0, 190));
		this->message.setFillColor(Box::getOutlineColor());
	}
	void Button::update(const sf::RenderWindow & window)
	{
		// create a cooldown to avoid calling the callback function every frame
		if (this->timer.getElapsedTime().asSeconds() > 0.5f)
		{
			this->clickable = true;
			this->timer.restart();
		}
		// if the button is clickable again..
		if (this->clickable)
		{
			// and mouse hovers over the button..
			if (this->mouseOver(window))
			{
				this->onHover();
				// and the button is pressed
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->onClick();
					if (this->callback)
						this->callback();
					this->clickable = false;
				}
			}
			// or the mouse doesn't hover over
			else
			{
				this->onUnhover();
			}
		}
	}
	bool Button::mouseOver(const sf::RenderWindow & window)
	{
		// get position of mouse
		const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		// return whether the mouse is in bounds of button
		return (this->getGlobalBounds().contains(mousePos));
	}
	/*void standardOnHover(InterfaceButton & button)
	{
		button.setFillColor(sf::Color(25, 25, 25, 170));
		button.setOutlineColor(sf::Color(222, 222, 222, 170));
		button.getTextObject().setFillColor(button.getOutlineColor());
	}
	void standardOnUnhover(InterfaceButton & button)
	{
		button.setFillColor(sf::Color(sf::Color(25, 25, 25, 50)));
		button.setOutlineColor(sf::Color(222, 222, 222, 240));
		button.getTextObject().setFillColor(button.getOutlineColor());
	}
	void standardOnClick(InterfaceButton & button)
	{
		button.setOutlineColor(sf::Color(0, 198, 0, 190));
		button.getTextObject().setFillColor(button.getOutlineColor());
	}*/
}
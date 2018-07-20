#include "TextButton.h"

namespace sen {
	TextButton::TextButton(const std::string & string)
		:TextBox(string)
	{
		// remember original settings
		this->originalColor = this->getFillColor();
		this->originalSize = this->getSize();
		this->originalCharacterSize = this->message.getCharacterSize();
	}
	void TextButton::render(sf::RenderTarget & target)
	{
		TextBox::render(target);
	}
	void TextButton::update(const sf::RenderWindow & window)
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
	void TextButton::onHover()
	{
		this->setFillColor(sf::Color(128, 128, 128, 80));
		this->setSize(this->originalSize * 1.25f);
	}
	void TextButton::onUnhover()
	{
		this->setFillColor(this->originalColor);
		this->setSize(this->originalSize);
	}
	void TextButton::onClick()
	{
		if (this->onClickFunc)
			this->onClickFunc();

		this->setFillColor(sf::Color::Green);
	}
	bool TextButton::mouseOver(const sf::RenderWindow & window)
	{
		// get position of mouse
		const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		// return whether the mouse in in bounds of button
		return (this->getGlobalBounds().contains(mousePos));
	}
}
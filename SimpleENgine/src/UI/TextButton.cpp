#include "TextButton.h"

namespace sen {
	TextButton::TextButton(const std::string & string)
		:TextBox(string)
	{
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
		if (this->timer.getElapsedTime().asSeconds() > 0.5f)
		{
			this->clickable = true;
			this->timer.restart();
		}
		if (this->clickable)
		{
			if (this->mouseOver(window))
			{
				this->onHover();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->onClick();
					this->clickable = false;
				}
			}
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
	void TextButton::onUnClick()
	{
		this->setFillColor(this->originalColor);
	}
	bool TextButton::mouseOver(const sf::RenderWindow & window)
	{
		const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		return (this->getGlobalBounds()	.contains(mousePos));
	}
}
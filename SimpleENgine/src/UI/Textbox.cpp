#include "Textbox.h"

namespace sen {
	TextBox::TextBox(const std::string & text)
		: message(text), Box()
	{
		// get text bounds and set a box around it
		sf::FloatRect bounds = this->message.getGlobalBounds();
		// make the box a little bigger so the text is clear
		sf::Vector2f size(bounds.width * 1.45f, bounds.height * 2.f);

		Box::setSize(size);
		Box::setFillColor(sf::Color::Transparent);
		Box::setOutlineColor(sf::Color::Red);
		Box::setOutlineThickness(-1.5f);
	}
	void TextBox::render(sf::RenderTarget & target)
	{
		// rendering must be in this order so the box wont cover the message
		Box::render(target);
		this->message.render(target);
	}
	void TextBox::setPosition(const sf::Vector2f & pos)
	{
		// set origin and then position of box and text
		Box::centerBox();
		Box::setPosition(pos);
		this->message.centerText();
		this->message.setPosition(pos);
		Box::move(this->message.getLocalBounds().left, this->message.getLocalBounds().top);
	}
	void TextBox::setFillColor(const sf::Color & color)
	{
		Box::setFillColor(color);
	}
	void TextBox::setTextFillColor(const sf::Color & color)
	{
		this->message.setFillColor(color);
	}
	void TextBox::setSize(const sf::Vector2f & size)
	{
		Box::setSize(size);
		this->centerBox();
		this->message.centerText();
	}

}

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
		Box::setFillColor(sf::Color(25,25,25, 170));
		Box::setOutlineColor(sf::Color(222,222,222, 170));
		this->message.setFillColor(Box::getOutlineColor());
		Box::setOutlineThickness(-2.5f);
	}
	void TextBox::render(sf::RenderTarget & target)
	{
		// rendering must be in this order so the box
		// wont cover the message
		Box::render(target);
		this->message.render(target);
	}
	void TextBox::setPosition(const sf::Vector2f & pos)
	{
		// set origin and then position of box and text
		Box::setPosition(pos);
		this->message.setPosition(pos);
		Box::move(this->message.getLocalBounds().left, this->message.getLocalBounds().top);
	}
}

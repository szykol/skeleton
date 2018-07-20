#include "Textbox.h"

namespace sen {
	TextBox::TextBox(const std::string & text)
		: Text(text), Box()
	{
		sf::FloatRect bounds = Text::getGlobalBounds();
		sf::Vector2f size(bounds.width * 1.15f, bounds.height * 2.f);
		Box::setSize(size);
		Box::setFillColor(sf::Color::Transparent);
		Box::setOutlineColor(sf::Color::Red);
		Box::setOutlineThickness(-1.5f);
	}
	void TextBox::render(sf::RenderTarget & target)
	{
		Box::render(target);
		Text::render(target);
	}
	void TextBox::setPosition(const sf::Vector2f & pos)
	{
		Box::centerBox();
		Box::setPosition(pos);
		Text::centerText();
		Text::setPosition(pos);
		Box::move(Text::getLocalBounds().left, Text::getLocalBounds().top);
	}
}

#include "TextButton.h"

namespace sen {
	TextButton::TextButton(const std::string & string)
		:TextBox(string)
	{
	}
	void TextButton::render(sf::RenderTarget & target)
	{
		TextBox::render(target);
	}
	void TextButton::onHover()
	{
	}
	void TextButton::onUnhover()
	{
	}
	void TextButton::onClick()
	{
	}
	void TextButton::onUnClick()
	{
	}
}
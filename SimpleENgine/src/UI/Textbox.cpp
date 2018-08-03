#include "Textbox.h"

namespace sen {
	TextBox::TextBox(const sf::String & string)
		: m_message(string), Box(), m_fitTextSize(false)
	{
		// get text bounds and set a box around it
		sf::FloatRect bounds = m_message.getLocalBounds();
		// make the box a little bigger so the text is clear
		sf::Vector2f size(bounds.width * 1.45f, bounds.height * 2.f);

		Box::setSize(size);
		Box::setFillColor(sf::Color(25,25,25, 170));
		Box::setOutlineColor(sf::Color(222,222,222, 170));
		m_message.setFillColor(Box::getOutlineColor());
		m_message.setOriginMode(OriginMode::CENTER);
		Box::setOutlineThickness(-2.5f);

		m_initialTextSize = m_message.getCharacterSize();
	}
	void TextBox::render(sf::RenderTarget & target)
	{
		if(m_fitTextSize)
		{
			// set text size to fix in the box
			if (m_message.haveBoundsChanged())
			{
				unsigned int textSize = m_initialTextSize;
				m_message.setCharacterSize(m_initialTextSize);
				while (isTextOutOfBounds() && textSize > 15)
					m_message.setCharacterSize(
						--textSize
					);
			}
		}
		// rendering must be in this order so the box
		// wont cover the message
		Box::render(target);
		m_message.render(target);
	}
	void TextBox::setPosition(const sf::Vector2f & pos)
	{
		// set origin and then position of box and text
		Box::setPosition(pos);
		m_message.setPosition(pos);
	}
	bool TextBox::isTextOutOfBounds()
	{
		return (m_message.getGlobalBounds().left
			< Box::getGlobalBounds().left + 20.f);
	}
	void TextBox::move(float offsetX, float offsetY)
	{
		Box::move(offsetX, offsetY);
		m_message.move(offsetX, offsetY);
	}
	void TextBox::move(const sf::Vector2f & offset)
	{
		Box::move(offset);
		m_message.move(offset);
	}
}

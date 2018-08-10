#include "Cursor.h"

namespace sen {
	Cursor::Cursor(const Text * text)
		: m_text(text), m_alpha(0),
		  m_delay(0.005f)
	{
		setCursor();
	}
	void Cursor::render(sf::RenderTarget & target)
	{
		if(!m_text)	return;

		Box::render(target);

		if (m_timer.getElapsedTime().asSeconds() > m_delay)
		{
			m_alpha+= 4;
			if (m_alpha >= 255)
			{
				m_alpha = 0;
			}
			/*else if (m_alpha <= 0)
			{
				m_alpha = 255;
			}*/
			sf::Color color = Box::getFillColor();
			color.a = m_alpha;
			Box::setFillColor(color);
			m_timer.restart();
		}
		if (m_text->haveBoundsChanged())
			setCursor();
	}
	void Cursor::setCursor()
	{
		if(!m_text)	 return;

		const float width = 1.5f;
		const sf::FloatRect textBounds = m_text->getGlobalBounds();
		const sf::Vector2f textPos = m_text->getPosition();
		sf::Vector2f cursorSize(width, m_text->getCharacterSize());
		Box::setSize(cursorSize);
		Box::setPosition(sf::Vector2f(
			textBounds.left + textBounds.width + 5.f,
			textPos.y
		));
		Box::setFillColor(m_text->getFillColor());
	}
	void Cursor::setTextRef(const Text* text)
	{
		m_text = text;
	}
}
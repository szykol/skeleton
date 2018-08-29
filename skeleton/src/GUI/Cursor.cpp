#include "Cursor.h"

namespace sen {
	Cursor::Cursor(const Text * text)
		: m_text(text), m_alpha(0),
		  m_delay(0.02f)
	{
		setCursor();
	}
	void Cursor::update(float deltaTime)
	{
		m_time += deltaTime;
		if (m_time > m_delay)
		{
			// blinking animation
			m_alpha += 4;
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
			m_time -= m_delay;
		}
	}
	void Cursor::render(sf::RenderTarget & target)
	{
		if(!m_text)	return;

		Box::render(target);

		if (m_text->haveBoundsChanged())
			setCursor();
	}
	void Cursor::setCursor()
	{
		if(!m_text)	 return;

		// places it at the end of text
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
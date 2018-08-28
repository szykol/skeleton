#include "Animation.h"

namespace sen {
	Animation::Animation(const sf::Texture & texture, const sf::Vector2u size, float delay)
		: m_delay(delay), m_size(size)
	{
		m_total = 0.f;
		m_currentFrame = { 0, 0 };
		m_frameRect.width = texture.getSize().x / size.x;
		m_frameRect.height = texture.getSize().y / size.y;
		m_frameRect.top = m_frameRect.left = 0;
	}
	const sf::IntRect& Animation::getTextureRect() const
	{
		return m_frameRect;
	}
	void Animation::update(float deltaTime)
	{
		m_total += deltaTime;

		if (m_total > m_delay)
		{
			m_total -= m_delay;

			m_currentFrame.x++;
			if (m_currentFrame.x >= m_size.x)
				m_currentFrame.x = 0;

			m_frameRect.left = m_currentFrame.x * m_frameRect.width;
		}

	}
}
#include "Animation.h"

namespace sen {
	Animation::Animation(const sf::Texture & texture, const sf::Vector2u size, float delay)
		: m_delay(delay), m_size(size)
	{
		m_total = 0.f;
		m_currentFrameX = 0;
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

			nextFrame();
		}
	}
	void Animation::setRow(unsigned int row)
	{
		if (row < m_size.y)
			m_frameRect.top = row * m_frameRect.height;
	}
	void Animation::nextFrame()
	{
		m_currentFrameX++;
		if (m_currentFrameX >= m_size.x)
			m_currentFrameX = 0;

		if (m_flipped)
		{
			m_frameRect.left = (m_currentFrameX + 1) * std::abs(m_frameRect.width);
			m_frameRect.width = -std::abs(m_frameRect.width);
		}
		else
		{
			m_frameRect.left = m_currentFrameX * m_frameRect.width;
			m_frameRect.width = std::abs(m_frameRect.width);
		}
	}
	void Animation::reset()
	{
		m_currentFrameX = m_size.x;
		nextFrame();
	}
}
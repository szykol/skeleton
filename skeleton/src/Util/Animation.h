#pragma once

#include <SFML/Graphics.hpp>

namespace sen {
	class Animation
	{
	private:
		float m_delay;
		float m_total = 0.f;
		bool m_flipped = false;
		sf::IntRect m_frameRect;
		sf::Vector2u m_size;
		unsigned int m_currentFrameX;
	public:
		Animation(const sf::Texture& texture, const sf::Vector2u size, float delay);
		const sf::IntRect& getTextureRect() const;
		void update(float deltaTime);
		void setRow(unsigned int row);
		void setFlippedFrame(bool flipped = true) { m_flipped = flipped; }
	};
}

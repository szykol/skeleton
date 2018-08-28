#pragma once

#include <SFML/Graphics.hpp>

namespace sen {
	class Animation
	{
	private:
		float m_delay;
		float m_total;
		sf::IntRect m_frameRect;
		sf::Vector2u m_size;
		sf::Vector2u m_currentFrame;
	public:
		Animation(const sf::Texture& texture, const sf::Vector2u size, float delay);
		const sf::IntRect& getTextureRect() const;
		void update(float deltaTime);
	};
}

#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace sen {
	class Transformable
	{
		std::unique_ptr<sf::Vector2f> m_goToPos;
	public:
		virtual void setPosition(float x, float y, float speed = 0.f);
		virtual void setPosition(const sf::Vector2f& pos, float speed = 0.f);
		virtual void move(float x, float y) = 0;
		virtual void move(const sf::Vector2f& vect) = 0;
		virtual void update();
		virtual ~Transformable();
	};
}

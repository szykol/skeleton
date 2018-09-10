#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace sen {
	class Transformable
	{
		bool m_needsUpdate = false;
		sf::Vector2f m_goToPos;
		sf::Vector2f m_direction;
	public:
		virtual void setPosition(float x, float y, float speed);
		virtual void setPosition(const sf::Vector2f& pos, float speed);
		virtual void setPosition(float x, float y) = 0;
		virtual void setPosition(const sf::Vector2f& pos) = 0;
		virtual const sf::Vector2f& getPosition() const = 0;
		virtual void move(float x, float y) = 0;
		virtual void move(const sf::Vector2f& vect) = 0;
		/*virtual*/ void update(float deltaTime);
		virtual ~Transformable();
	};
}

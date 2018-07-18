#pragma once
#include <SFML/Graphics.hpp>


namespace sen {
	class Box : public sf::RectangleShape
	{
	public:
		Box(const sf::Vector2f &size) : sf::RectangleShape(size) {}
		Box(const sf::Vector2f &size, const sf::Vector2f &pos) : sf::RectangleShape(size) { this->setPosition(pos); }
		void blurBackground(float ammount);
	};
}
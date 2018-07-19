#pragma once
#include <SFML/Graphics.hpp>


namespace sen {
	class Box : public sf::RectangleShape
	{
	private:
		sf::Shader  *shader = nullptr;
		sf::Sprite  *sprite = nullptr;
		sf::Texture *texture = nullptr;
	public:
		Box(const sf::Vector2f &size) : sf::RectangleShape(size) {}
		Box(const sf::Vector2f &size, const sf::Vector2f &pos) : sf::RectangleShape(size) { this->setPosition(pos); }
		void draw(sf::RenderWindow &window);	
		void blurBackground(float ammount, sf::RenderWindow&);
	};
}
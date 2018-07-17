#pragma once
#include <SFML/Graphics.hpp>

namespace sen {
	/*  this class is just a basic wrapper for sf::Text class.
		It provides one method: centerText that centers the text around its position
	*/
	class text : public sf::Text
	{

	public:
		void centerText();
		text(const sf::String &string, const sf::Font &font, unsigned int fontSize = 30U) : sf::Text(string, font, fontSize) { this->centerText(); }
		void draw(sf::RenderTarget &renderer) { renderer.draw(*this); }
		~text();
	};
}

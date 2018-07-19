#pragma once
#include <SFML/Graphics.hpp>
#include "Managers/FontManager.h"

namespace sen {
	/**
		This class is just a basic wrapper for sf::Text class.
		It provides one method: centerText that centers the text around its position.
	*/
	class Text : public sf::Text
	{
	public:
		/**
			This constructor lets you specify the string, fontsize and font that will be used in this object.

			@param string String that will be displayed.
			@param fontSize Font size. Default value = 30U.
			@param font Font used to display the text. Default font is Roboto.
		*/
		Text(const sf::String &string, unsigned int fontSize = 30U, const sf::Font &font = FontManager::get("default")) : sf::Text(string, font, fontSize) { this->centerText(); }
		/**
			Sets it's origin exactly in the middle.
		*/
		void centerText();
		/**
			Draws the box on the target
		
			@param target Target you want to draw text on
		*/
		void draw(sf::RenderTarget &target);
		~Text();
	};
}

#pragma once
#include <SFML/Graphics.hpp>
#include "../Managers/FontManager.h"

namespace sen {
	/**
		Lets you choose where to set the origin
	*/
	enum class OriginMode {CENTER, TOPLEFT};
	/**
		Just a basic wrapper for sf::Text class.
		Lets you easily change origin of the text using OriginMode enum.
	*/
	class Text : public sf::Text
	{
	private:
		OriginMode originMode;
	public:
		/**
			Lets you specify the string, fontsize and font that will be used in this object.

			@param string String that will be displayed.
			@param fontSize Font size. Default value = 30U.
			@param font Font used to display the text. Default font is Roboto.
		*/
		Text(const sf::String &string, unsigned int fontSize = 30U, 
			 const sf::Font &font = FontManager::get("default"));
		/**
			Draws the box on the target
		
			@param target Target you want to draw text on
		*/
		void render(sf::RenderTarget &target);
		/**
			Sets character size of text and resets the origin.

			@param size Size of text
		*/
		void setCharacterSize(unsigned int size);
		/**
			Sets origin mode.
			OriginMode::CENTER sets origin to the middle of the object's bounds.
			OriginMode::TOPLEFT sets origin to the top left which is default
			in SFML library. You can still set origin to whatever you need using
			setOrigin function.

			@param mode Where to set origin
		*/
		void setOriginMode(OriginMode mode);
		/**
			Returns the origin mode.
			OriginMode::CENTER sets origin to the middle of the object's bounds.
			OriginMode::TOPLEFT sets origin to the top left which is default
			in SFML library.

			@return The origin mode
		*/
		OriginMode getOriginMode() const { return this->originMode; }
		~Text();
	};
}

#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Box.h"

namespace sen {
	/**
		This class extends both Text and Box classes

		It can be used as a simple text inside of a box
	*/
	class TextBox : public Text, public Box
	{
	public:
		/**
			Sets the text, and then sets size of the box.

			@param text Text displayed inside box.
		*/
		TextBox(const std::string &text);
		/**
			Draws the TextBox on the target.
		
			@param target Target you want to draw box on.
		*/
		void draw(sf::RenderTarget &target);
		/**
			Sets the position of TextBox and centers it.
			
			@param pos Position
		*/
		void setPosition(const sf::Vector2f &pos);
	};
}
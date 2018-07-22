#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Box.h"

namespace sen {
	/**
		Extends both Text and Box classes

		It can be used as a simple text inside of a box
	*/
	class TextBox : public Box
	{
	protected:
		Text message;
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
		void render(sf::RenderTarget &target);
		/**
			Sets the position of TextBox and centers it.
			
			@param pos Position
		*/
		void setPosition(const sf::Vector2f &pos);
		/**
			Returns the text object of the textbox.
			If you want to perform any operations on the text
			that's inside of the box, that method returns it

			@return Text object inside of the box
		*/
		Text& getTextObject() { return this->message; }
	};
}
#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Box.h"

namespace sen {
	/**
	 *	Extends both Text and Box classes
     *
	 *	It can be used as a simple text inside of a box
	 */
	class TextBox : public Box
	{
	protected:
		Text m_message;
		unsigned int m_initialTextSize;
		bool m_fitTextSize;
	public:
		/**
		 *	Sets the text, and then sets size of the box.
         *
		 *	@param string Text displayed inside box.
		 */
		explicit TextBox(const sf::String &string);
		/**
		 *	Draws the TextBox on the target.
		 *
		 *	@param target Target you want to draw box on.
		 */
		void render(sf::RenderTarget &target);
		/**
		 *	Sets the position of TextBox and centers it.
		 *	
		 *	@param pos Position
		 */
		void setPosition(const sf::Vector2f &pos);
		/**
		 *	Returns the text object of the textbox.
		 *	If you want to perform any operations on the text
		 *	that's inside of the box, that method returns it
         *
		 *	@return Text object inside of the box
		 */
		Text& getTextObject() { return m_message; }
		bool isTextOutOfBounds();
		virtual ~TextBox() = default;
		void move(float offsetX, float offsetY);
		inline void setFitTextSize(bool fit = false) {m_fitTextSize = fit;}
		void move(const sf::Vector2f& offset);
	};
}
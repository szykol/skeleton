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
		sf::Vector2f m_textOffset;
	public:
		using Box::setPosition;
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
		 *	@param x,y new Position
		 */
		virtual void setPosition(float x, float y) override;
		/**
		 *	Sets the position of TextBox and centers it.
		 *	
		 *	@param pos Position
		 */
		virtual void setPosition(const sf::Vector2f &pos)  override;
		/**
		 *	Returns the text object of the textbox.
		 *	If you want to perform any operations on the text
		 *	that's inside of the box, that method returns it
         *
		 *	@return Text object inside of the box
		 */
		Text& getTextObject() { return m_message; }
		/** 
		 * @brief  Fits the text size if it would 
		 * come out of bounds of the TextBox
		 * @note This will override setting 
		 * custom character size as it will 
		 * be setting the smallest character 
		 * size possible
		 * @param  fit: If true the text will be
		 * controlled to fit inside of the box
		 * @retval None
		 */
		inline void setFitTextSize(bool fit = false) {m_fitTextSize = fit;}
		/** 
		 * @brief  Sets texts offset from center.
		 * @param  offset: new offset (set {0.f,0.f} to make it 
		 * again at the center)
		 * @retval None
		 */
		inline void setTextOffset(const sf::Vector2f& offset) {m_textOffset = offset;}
		/** 
		 * @brief  Returns true if text is outside of
		 * TextBox bounds
		 * @note   Needed for implementation
		 * @retval 
		 */
		bool isTextOutOfBounds();
		/** 
		 * @brief  Let's you move this object
		 * as every other one, it moves the
		 * text by it's offset (default is {0.f,0.f})
		 * @param  offsetX: x coord of offset
		 * @param  offsetY: y coord of offset
		 * @retval None
		 */
		void move(float offsetX, float offsetY);
		/** 
		 * @brief  Let's you move this object
		 * as every other one, it moves the
		 * text by it's offset (default is {0.f,0.f})
		 * @param  offset new offset
		 * @retval None
		 */
		void move(const sf::Vector2f& offset);


	};
}
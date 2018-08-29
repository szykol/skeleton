#pragma once

#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Box.h"

namespace sen {
	/** 
	 * @brief  Flashing cursor. You can apply it to any
	 * kind of Text class object
	 * @note   Resizing and repositioning of the cursor 
	 * (when the text changes size) is done automaticaly
	 * @retval None
	 */
	class Cursor : public Box, sf::NonCopyable
	{
	private:
		float m_time = 0.f;
		unsigned char m_alpha;
		const Text* m_text;
		float m_delay;
	public:
		/** 
		 * @brief  Keeps the text address in memory. Positions
		 * itself according to the size and position of text.
		 * @param  text: Text pointer, can be null
		 */
		explicit Cursor(const Text* text = nullptr);
		/** 
		 * @brief  Renders the Cursor on the screen, Makes
		 * a blinking effect.
		 * @param  target: Target you want to draw on
		 * @retval None
		 */
		void update(float deltaTime);
		void render(sf::RenderTarget& target);
		/** 
		 * @brief  Changes the text addres. If not null
		 * the cursor will be placed according to the size
		 * and position of text.
		 * @param  text: Text pointer, can be null
		 * @retval None
		 */
		void setTextRef(const Text* text);
	private:
	    /** 
          * @brief  Sets the size and position of Cursor
		  * according to position and size of text.
          * @note   This needs to be called everytime
		  * the text size has changed. But for now 
		  * it is all done automatically
          * @retval None
          */
		void setCursor();
	};
}
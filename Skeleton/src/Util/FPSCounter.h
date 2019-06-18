#pragma once

#include <SFML/Graphics.hpp>
#include "../GUI/Text.h"

namespace sen {
	/**
	 *	Basic fps counter. Extends functionality of the Text class
	 *	so you are able to set the color of text, position etc
	*/
	class FPSCounter : sf::NonCopyable, public Text
	{
	private:
		float m_fpsAmmount;
		float m_updateDelay;
		float m_elapsedTime;
	public:
		/**
		 *	Sets the fps counter in the left top corner.
		 */
		FPSCounter();
		/**
		 *	Updates itself and shows last fps count when
		 *	fps counter was updated (It doesn't count average
		 *	fps)
		 */
		void update(float deltaTime);
		/**
		 *	Renders fps counter on screen
		 *
		 *	@param target Target
		 */
		void render(sf::RenderTarget &target);
		/**
		 *	Sets the update delay. You specify the ammount 
		 *	of time that needs to pass in order to update
		 *	the fps counter
		 *
		 *	@param updateDelay Delay between each update
		 */
		inline void setUpdateDelay(float updateDelay = 0.15f) { m_updateDelay = updateDelay; }
	private:
		/**
		 *	string updates automatically
		 */
		using Text::setString;
	};
}
#pragma once

#include <SFML/Graphics.hpp>

namespace sen {
	/** 
	 * @brief  Basic animation class that works with
	 * spritesheets. Gets the texture
	 * to calculate it's size. Gets a number of rows
	 * and columns of frames, then gets a delay between
	 * each frame. Is able to flip the image and change
	 * the row of frames.
	 */
	class Animation
	{
	private:
		float m_delay;
		float m_total = 0.f;
		bool m_flipped = false;
		sf::IntRect m_frameRect;
		sf::Vector2u m_size;
		unsigned int m_currentFrameX;
	public:
		/** 
		 * @brief  Calculates the size of frame, sets
		 * the floatRect to the first image.
		 * @note   It doesn't keep the texture in memory
		 * it's just needed to do a couple calculations
		 * @param  texture: texture to get the size of a whole
		 * spritesheet
		 * @param  size: columns and rows of images
		 * @param  delay: delay between each frame
		 */
		Animation(const sf::Texture& texture, const sf::Vector2u size, float delay);
		/** 
		 * @brief  Returns the current textureRect
		 */
		const sf::IntRect& getTextureRect() const;
		/** 
		 * @brief  Switches between frames after delay
		 * @param  deltaTime: Time since last frame
		 */
		void update(float deltaTime);
		/** 
		 * @brief  Sets the new row of images
		 */
		void setRow(unsigned int row);
		/** 
		 * @brief  Flips the image from right to left. 
		 * @note   Useful when you need your character to face
		 * the other direction
		 * @param  flipped: set to true if not passed by user
		 */
		void setFlippedFrame(bool flipped = true) { m_flipped = flipped; }
		/**
		 * @brief  Sets the next frame in the animation
		 */
		void nextFrame();
		/**
		 * @brief  Sets the first frame in animiation
		 */
		void reset();
	};
}

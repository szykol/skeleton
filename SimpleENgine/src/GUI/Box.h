#pragma once
#include <SFML/Graphics.hpp>
#include "text.h"
namespace sen {
	/** 
	 *	Just a wrapper for a sf::RectangleShape class.
	 *	It provides a couple of methods that are handy such as setOriginMode
	 *	that lets you easily change the origin to the center or top left corner.
	 *	
	 *	In the future, it will let you blur it's background.
	 */
	class Box : public sf::RectangleShape
	{
	private:
		OriginMode m_originMode;
		/*sf::Shader  *shader = nullptr;
		sf::Sprite  *sprite = nullptr;
		sf::Texture *texture = nullptr;*/
	public:
		/**
		 *	Default constructor of the Box, it just calls sf::RectangleShape's 
		 *	default constructor and sets origin mode to CENTER
		 */
		Box() : sf::RectangleShape() { setOriginMode(OriginMode::CENTER); }
		/**
		 *	Lets you specify the size of the Box.
		 *	It also sets origin mode to center.
		 *
		 *	@param size Size of the box
		 */
		explicit Box(const sf::Vector2f &size);
		/**
		 *	Lets you specify both size and position of the box.
		 *	It also sets origin mode to center.
		 *
		 *	@param size Size of the box
		 *	@param pos Position of the box
		 */
		Box(const sf::Vector2f &size, const sf::Vector2f &pos);
		/**
		 *	Draws the box on the target
		 *
		 *	@param target Target you want to draw the box on
		 */
		void render(sf::RenderTarget &target);	
		/**
		 *	Sets origin mode.
		 *	OriginMode::CENTER sets origin to the middle of the object's bounds.
		 *	OriginMode::TOPLEFT sets origin to the top left which is default
		 *	in SFML library. You can still set origin to whatever you need using
		 *	setOrigin function.
 		 *
		 *	@param mode Where to set origin
		 */
		void setOriginMode(OriginMode mode);
		/**
		 *	Returns the origin mode.
		 *	OriginMode::CENTER sets origin to the middle of the object's bounds.
		 *	OriginMode::TOPLEFT sets origin to the top left which is default
		 *	in SFML library.
		 *
		 *	@return The origin mode
		 */
		OriginMode getOriginMode() const { return m_originMode; }
		/**
		 *	Calls sf::RectangleShape setSize method and if the originMode
		 *	is set to CENTER resets the origin to the middle.
		 *
		 *	@param size New size
		 */
		void setSize(const sf::Vector2f &size);
		virtual ~Box() = default;
		/**
		 * ! NOT WORKING
		 *	Let's you blur the background of the box
		 *
		 *	@param ammount Ammount of the blur effect
		 *	@param window Background of box
		 */
		//void blurBackground(float ammount, sf::RenderWindow& window);
	};
}
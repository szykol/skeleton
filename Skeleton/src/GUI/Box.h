#pragma once

#include <SFML/Graphics.hpp>

#include "Transformable.h"
#include "Text.h"

namespace sen {
	/** 
	 *	Just a wrapper for a sf::RectangleShape class.
	 *	It provides a couple of methods that are handy such as setOriginMode
	 *	that lets you easily change the origin to the center or top left corner.
	 */
	class Box : public sf::RectangleShape, public Transformable
	{
	private:
		OriginMode m_originMode;
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

		/* all of those methods are overriden to enable animating the movement
			of this object */
		virtual void setPosition(float x, float y, float speed)			override;
		virtual void setPosition(float x, float y)						override;
		virtual void setPosition(const sf::Vector2f& pos)				override;
		virtual void setPosition(const sf::Vector2f& pos, float speed)  override;
		virtual const sf::Vector2f& getPosition() const					override;
		virtual void move(float x, float y)								override;
		virtual void move(const sf::Vector2f& vect)						override;

		virtual ~Box() = default;

		Box(const Box&) = default;
		Box& operator=(const Box&) = default;
		Box(Box&&) = default;
		Box& operator=(Box&&) = default;
	};
}
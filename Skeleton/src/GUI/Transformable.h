#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace sen {
	/**
	 * @brief  Basic Transformable class that lets 
	 * animate its movements (for now changing positions only)
	 */
	class Transformable
	{
		bool m_needsUpdate = false;
		sf::Vector2f m_goToPos;
		sf::Vector2f m_direction;
	public:
		/**
		 * @brief  This basically enables you to animate the 
		 * movement if you specify the speed.
		 */		
		virtual void setPosition(float x, float y, float speed);
		virtual void setPosition(const sf::Vector2f& pos, float speed);
		/**
		 * @brief  These are the methods that need to be overriden
		 * in derived classes to actually be able to move 
		 * the object
		 */
		virtual void setPosition(float x, float y) = 0;
		virtual void setPosition(const sf::Vector2f& pos) = 0;
		/**
		 * @brief  Used to specify the position of an entity
		 */
		virtual const sf::Vector2f& getPosition() const = 0;
		/**
		 * @brief  These are the methods that need to be overriden
		 * in derived classes to actually be able to move 
		 * the object
		 */
		virtual void move(float x, float y) = 0;
		virtual void move(const sf::Vector2f& vect) = 0;
       /**
        * @brief  This is used only for animating 
		* the movement of an object
        * @param  deltaTime: time that has passed since last frame
        * @retval None
        */
		void update(float deltaTime);
		virtual ~Transformable();

		Transformable() = default;
		Transformable(const Transformable&) = default;
		Transformable& operator=(const Transformable&) = default;
		Transformable(Transformable&&) = default;
		Transformable& operator=(Transformable&&) = default;
	};
}

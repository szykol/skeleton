#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace sen {
	/** 
	 * @brief  This class moves the sf::Transformables
	 * between two positions by the given time
	 */
	class AnimationController : sf::NonCopyable
	{
	private:
		struct Transformable
		{
			sf::Transformable* address;
			sf::Vector2f goToPosition;
			sf::Vector2f stepVect;
		};
		static std::vector<Transformable> s_transformables;
		static float s_time;
		static float s_stepTime;
	public:
		/** 
		 * @brief  add a new transformable
		 * @note   When it reaches the goal point,
		 * it gets removed from the controller (but not from memory)
		 * @note   If the transformable gets removed (for example
		 * removed from stack) it needs to be manually removed
		 * from this controller before it gets deleted 
		 * @param  address: address of the transformable
		 * @param  goToPosition: the goal position
		 * @param  speed: the lower the faster
		 * @retval None
		 */
		static void add(sf::Transformable* address,
			const sf::Vector2f& goToPosition, float speed
		);
		/** 
		 * @brief  remove the transformable from 
		 * maintained transformables.
		 * @note   This is useful when the object
		 * maintained by the controller is about
		 * to get removed from memory
		 * @param  address: address of a transformable
		 * to get removed
		 */
		static void remove(sf::Transformable* address);
		/** 
		 * @brief  check if the transformable is 
		 * maintained by the controller
		 * @param  address: address of the transformable
		 * @retval 
		 */
		static bool isMaintained(sf::Transformable* address);
		/** 
		 * @brief  Updates and moves all the transformables to the given
		 * point
		 * @param  deltaTime: time since last frame
		 */
		static void update(float deltaTime);
	};
}
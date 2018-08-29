#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

namespace sen {
	/** 
	 * @brief  Basic function that will normalize 
	 * any sf::Vector2
	 * @param  &vector: vector you want to normalize
	 * @retval Normalized vector
	 */
	template<typename T>
	const sf::Vector2<T> normalize_vector(const sf::Vector2<T> &vector)
	{
		sf::Vector2<T> temp_vector;
		temp_vector = vector / std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
		return temp_vector;
	}
	/**
	 * @brief Returns exact distance between two points
	 */
	float getDistance(const sf::Vector2f& a, const sf::Vector2f& b);
	/**
	 * @brief Returns inexact distance between two points.
	 * This function requires less maths to compute the distance
	 * but is much less exact.
	 * @note This function could be useful if you need to specify
	 * which object is closer to a certain point, or you don't need 
	 * accuracy
	 */
	float getInexactDistance(const sf::Vector2f& a, const sf::Vector2f& b);
}
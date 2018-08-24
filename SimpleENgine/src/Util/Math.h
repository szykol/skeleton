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
}
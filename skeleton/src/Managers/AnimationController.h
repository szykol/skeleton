#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../GUI/Transformable.h"

namespace sen {
	/** 
	 * @brief  This class moves the sf::Transformables
	 * between two positions by the given time
	 */
	class AnimationController : sf::NonCopyable
	{
		static std::vector<Transformable*> m_entities;
	public:
		static void add(Transformable* entity);
		static void remove(Transformable* entity);
		static void update();
	};
}
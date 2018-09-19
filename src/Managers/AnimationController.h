#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../GUI/Transformable.h"

namespace sen {
	/** 
	 * @brief  This class works with objects derived
	 * from sen::Transformable. It holds all objects
	 * that need to be repositioned and calls the
	 * update method. The GUI objects have built in
	 * adding and removing themselves from AnimationController
	 */
	class AnimationController
	{
		static std::vector<Transformable*> m_entities;
	public:
		/**
		 * @brief  Add a new entity 
		 */
		static void add(Transformable* entity);
		/**
		 * @brief  Remove a entity if it has ended animating
		 */
		static void remove(Transformable* entity);
		/**
		 * @brief  Calls update method of each entity
		 */
		static void update(float deltaTime);
	};
}
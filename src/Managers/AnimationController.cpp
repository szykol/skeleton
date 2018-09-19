#include "AnimationController.h"
#include "../Util/Math.h"

#include <iostream>

namespace sen {
	std::vector<Transformable*> AnimationController::m_entities;

	void AnimationController::add(Transformable * entity)
	{
		auto temp = std::find_if(m_entities.begin(), m_entities.end(), [&entity](Transformable* t) {
			return t == entity;
		});

		if (temp == m_entities.end())
			m_entities.push_back(entity);

	}
	void AnimationController::remove(Transformable * entity)
	{
		auto temp = std::find_if(m_entities.begin(), m_entities.end(), [&entity](Transformable* t) {
			return t == entity;
		});

		if (temp != m_entities.end())
			m_entities.erase(temp);
	}
	void AnimationController::update(float deltaTime)
	{
		for (auto& ent : m_entities)
			ent->update(deltaTime);
	}
}
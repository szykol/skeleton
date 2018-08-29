#include "AnimationController.h"
#include "../Util/Math.h"

#include <iostream>

namespace sen {
	float AnimationController::s_stepTime = 0.01f;
	std::vector<AnimationController::Transformable> AnimationController::s_transformables;
	float AnimationController::s_time = 0.f;

	void AnimationController::add(sf::Transformable* address, const sf::Vector2f& goToPosition, float speed)
	{
		if (isMaintained(address)) return;

		/*sf::Vector2f stepVect = (goToPosition - address->getPosition()) * (s_stepTime / timeNeeded);*/

		sf::Vector2f stepVect = goToPosition - address->getPosition();
		stepVect *= s_stepTime;
		stepVect /= speed;

		Transformable temp{ address, goToPosition, stepVect };

		s_transformables.push_back(temp);
	}
	void AnimationController::remove(sf::Transformable* address)
	{
		if (!isMaintained(address)) return;
		
		auto toRemove = std::find_if(s_transformables.begin(), s_transformables.end(),
			[&address](Transformable t) {
				return t.address == address;	
		});

		if (toRemove != s_transformables.end());
			s_transformables.erase(toRemove);
	}
	bool AnimationController::isMaintained(sf::Transformable* address)
	{
		return std::find_if(s_transformables.begin(), s_transformables.end(),
			[&address](Transformable t) {
			return t.address == address;
		}) != s_transformables.end();
	}
	void AnimationController::update(float deltaTime)
	{
		s_time += deltaTime;
		if (s_time > s_stepTime)
		{
			s_time = 0.f;
			for (auto& transformable : s_transformables)
			{
				float dist = getInexactDistance(transformable.goToPosition, transformable.address->getPosition());
				// close to the goal position
				if (dist < 1.f)
				{
					transformable.address->setPosition(transformable.goToPosition);
					remove(transformable.address);
				}
				else
				{
					transformable.address->move(transformable.stepVect);
				}
			}
		}
	}
}
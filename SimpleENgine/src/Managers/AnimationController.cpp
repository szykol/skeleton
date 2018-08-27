#include "AnimationController.h"

#include <iostream>

namespace sen {
	float AnimationController::s_stepTime = 0.001f;
	std::vector<AnimationController::Transformable> AnimationController::s_transformables;
	sf::Clock AnimationController::s_animationClock;

	void AnimationController::add(sf::Transformable* address, const sf::Vector2f& goToPosition, float timeNeeded)
	{
		if (isMaintained(address)) return;

		/*sf::Vector2f stepVect = (goToPosition - address->getPosition()) * (s_stepTime / timeNeeded);*/

		sf::Vector2f stepVect = goToPosition - address->getPosition();
		stepVect *= s_stepTime;
		stepVect /= timeNeeded;

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
	void AnimationController::update()
	{
		static unsigned ticks = 0;
		if (s_animationClock.getElapsedTime().asSeconds() > s_stepTime)
		{
			s_animationClock.restart();
			for (auto& transformable : s_transformables)
			{
				sf::Vector2f dist = transformable.goToPosition - transformable.address->getPosition();
				// close to the goal position
				if (dist.x + dist.y < 1.f)
				{
					transformable.address->setPosition(transformable.goToPosition);
					remove(transformable.address);
				}
				else
				{
					ticks++;
					transformable.address->move(transformable.stepVect);
				}
			}
		}
	}
}
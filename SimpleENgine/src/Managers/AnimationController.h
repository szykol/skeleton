#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace sen {
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
		static void add(sf::Transformable* address,
			const sf::Vector2f& goToPosition, float speed
		);
		static void remove(sf::Transformable* address);
		static bool isMaintained(sf::Transformable* address);
		static void update(float deltaTime);
	};
}


/*
// oblicza jaki dystans ma pokonac w kazdym kroku
sen::AnimationController::add(&text, sf::Vector2f(0.f, 100.f), 20s);


// potem w AnimationController::update()
// nie usuwa obiektow z pamieci tylko ze swojego
// kontenera (co sie dzieje kiedy zniknie obiekt,
// ktory dalej jest trzymany w animationcontrollleR?)
for (auto transformable : m_transformables)
{
if (transformable.getPos != transformable.goToPos)
transformable.move(transformable.getStepVector);
else
{
transformable.m_ptr->setPos(goToPos);
m_transformables.remove(this one);
}
}

struct Transformable
{
sf::Transformable& m_ptr;
sf::Vector2f goToPos;
sf::Vector2f step;
float time?
};
*/
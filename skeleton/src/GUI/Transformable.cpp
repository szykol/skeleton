#include "Transformable.h"

#include "../Managers/AnimationController.h"

namespace sen {
	void Transformable::setPosition(float x, float y, float speed)
	{
		if (speed > 0.f)
		{
			m_goToPos = std::make_unique<sf::Vector2f>(x, y);
		    AnimationController::add(this);
		}
	}

	void Transformable::setPosition(const sf::Vector2f & pos, float speed)
	{
		if (speed > 0.f)
		{
			m_goToPos = std::make_unique<sf::Vector2f>(pos);
			AnimationController::add(this);
		}
	}
	Transformable::~Transformable()
	{
		 AnimationController::remove(this);
	}

	void Transformable::update()
	{
		// for now just set it to this position
		if (m_goToPos)
			move(*m_goToPos);
	}
}

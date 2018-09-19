#include "Transformable.h"

#include "../Managers/AnimationController.h"
#include "../Util/Math.h"

namespace sen {
	void Transformable::setPosition(float x, float y, float speed)
	{
		if (speed > 0.f)
		{
			m_goToPos = sf::Vector2f(x, y);
			m_direction = (m_goToPos - getPosition()) * speed;
			AnimationController::add(this);
			m_needsUpdate = true;
		}
		else
			setPosition(x, y);
	}

	void Transformable::setPosition(const sf::Vector2f & pos, float speed)
	{
		if (speed > 0.f)
		{
			m_goToPos = pos;
			m_direction = (m_goToPos - getPosition()) * speed;
			AnimationController::add(this);
			m_needsUpdate = true;
		}
		else
			setPosition(pos);
	}
	Transformable::~Transformable()
	{
		 AnimationController::remove(this);
	}

	void Transformable::update(float deltaTime)
	{
		// for now just set it to this position
		if (m_needsUpdate)
		{
			if (getInexactDistance(m_goToPos, getPosition()) < 5.f)
			{
				setPosition(m_goToPos);
				m_needsUpdate = false;
			}
			else
				move(m_direction * deltaTime);
		}
		else
			AnimationController::remove(this);
	}
}

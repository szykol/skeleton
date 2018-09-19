#include "Math.h"

namespace sen {
	float getDistance(const sf::Vector2f & a, const sf::Vector2f & b)
	{
		return std::sqrt(std::pow(a.x + b.x, 2.0) + std::pow(a.y + b.y, 2.0));
	}
	float getInexactDistance(const sf::Vector2f & a, const sf::Vector2f & b)
	{
		auto temp = a - b;
		return std::abs(temp.x + temp.y);
	}
}

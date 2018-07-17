#include "text.h"


namespace sen {
	// Centers the text around its position
	void text::centerText()
	{
		sf::FloatRect bounds = this->getLocalBounds();
		this->setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
	}

	text::~text()
	{
	}
}
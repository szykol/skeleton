#include "Text.h"
#include "Box.h"

namespace sen {
	void Text::centerText()
	{
		// get bounds of text, set origin in the middle 
		sf::FloatRect bounds = this->getLocalBounds();
		this->setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
	}

	void Text::render(sf::RenderTarget & target)
	{
		target.draw(*this);
	}

	void Text::setCharacterSize(unsigned int size)
	{
		sf::Text::setCharacterSize(size);
		// when size of text changes we need to update the origin
		this->centerText();
	}

	Text::~Text()
	{
	}
}
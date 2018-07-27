#include "Text.h"
#include "Box.h"

namespace sen {
	Text::Text(const sf::String & string, unsigned int fontSize, const sf::Font & font)
		: sf::Text(string, font, fontSize)
	{
		this->setOriginMode(OriginMode::CENTER);
	}

	void Text::render(sf::RenderTarget & target)
	{
		target.draw(*this);
	}

	void Text::setCharacterSize(unsigned int size)
	{
		sf::Text::setCharacterSize(size);

		// when size of text changes and text is in center mode we need to update the origin
		// so the text will be set in the middle (the bounds have changed)
		if (this->originMode == OriginMode::CENTER)
		{
			sf::FloatRect bounds = this->getLocalBounds();
			this->setOrigin(sf::Vector2f(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f));
		}
	}

	void Text::setOriginMode(OriginMode mode)
	{
		if (this->originMode == mode)
			return;

		this->originMode = mode;
		
		if (this->originMode == OriginMode::CENTER)
		{
			sf::FloatRect bounds = this->getLocalBounds();
			this->setOrigin(sf::Vector2f(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f));
		}
		else
		{
			this->setOrigin(0.f, 0.f);
		}
	}

	void Text::setString(const sf::String & string)
	{
		sf::Text::setString(string);
		if (this->originMode == OriginMode::CENTER)
		{
			sf::FloatRect bounds = this->getLocalBounds();
			this->setOrigin(sf::Vector2f(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f));
		}
	}

	Text::~Text()
	{
	}
}
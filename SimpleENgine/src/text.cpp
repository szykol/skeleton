#include "Text.h"
#include "Box.h"

namespace sen {
	// Centers the text around its position
	void Text::centerText()
	{
		sf::FloatRect bounds = this->getLocalBounds();
		this->setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
	}

	void Text::draw(sf::RenderTarget & target)
	{
		target.draw(*this);
		sf::FloatRect bounds = this->getLocalBounds();

		/*Box temp(sf::Vector2f(bounds.width, bounds.height), this->getPosition());
		std::cout << this->getPosition().x<<this->getPosition().y << std::endl;
		temp.setFillColor(sf::Color::White);
		target.draw(temp);*/
	}

	Text::~Text()
	{
	}
}
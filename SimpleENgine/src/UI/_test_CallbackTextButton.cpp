#include "_test_CallbackTextButton.h"

namespace sen {
	CallbackTextButton::CallbackTextButton(const std::string & string)
		: TextBox(string)
	{
		onHover = [](sen::CallbackTextButton& button) {
			button.setFillColor(sf::Color::Red);
		};
		onUnhover = [](sen::CallbackTextButton& button) {
			button.setFillColor(sf::Color::Blue);
		};
		onClick = [](sen::CallbackTextButton& button) {
			button.setFillColor(sf::Color::Green);
		};
	}
	void CallbackTextButton::update(const sf::RenderWindow & window)
	{
		if (this->onHover && this->mouseOver(window))
		{
			this->onHover(*this);
			if (this->onClick && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				this->onClick(*this);
		}
		else if (this->onUnhover)
			this->onUnhover(*this);
	}
	bool CallbackTextButton::mouseOver(const sf::RenderWindow & window)
	{
		const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		return (this->getGlobalBounds().contains(mousePos));
	}
}

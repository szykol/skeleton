#include "ButtonController.h"

namespace sen {
	ButtonController::ButtonController(const std::vector<Button*>& buttons)
		: buttons(buttons)
	{
		this->placeButtons();
	}
	void ButtonController::update(sf::RenderWindow & window)
	{
		if (timer.getElapsedTime().asSeconds() > 0.1f)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (this->activeIndex >= this->buttons.size() - 1)
					this->activeIndex = 0;
				else
					this->activeIndex++;
				timer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (this->activeIndex <= 0)
					this->activeIndex = this->buttons.size() - 1;
				else
					this->activeIndex--;
				timer.restart();
			}
		}

		for (int i = 0; i < this->buttons.size(); ++i)
		{
			if (this->buttons[i]->mouseOver(window))
			{
				this->activeIndex = i;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->buttons[this->activeIndex]->onClick();
					this->buttons[this->activeIndex]->callback();
				}
			}
		}

		for (int i = 0; i < this->buttons.size(); ++i)
		{
			if (this->activeIndex != i)
				this->buttons[i]->onUnhover();
		}

		this->buttons[activeIndex]->onHover();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			this->buttons[activeIndex]->callback();
	}
	void ButtonController::render(sf::RenderTarget & target)
	{
		for (auto button : this->buttons)
		{
			button->render(target);
		}
	}
	void ButtonController::placeButtons()
	{
		for (int i = 0; i < this->buttons.size(); ++i)
		{
			this->buttons[i]->setPosition(sf::Vector2f(400.f, i * 200 + this->buttons[i]->getSize().y));
		}
	}
}
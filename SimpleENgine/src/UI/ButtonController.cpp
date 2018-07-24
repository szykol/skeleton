#include "ButtonController.h"

namespace sen {
	ButtonController::ButtonController(const std::vector<Button*>& buttons)
		: buttons(buttons)
	{
	}
	ButtonController::ButtonController(const std::vector<Button*> buttons, const sf::RenderWindow & window)
		: buttons(buttons)
	{
		this->placeButtons(window);
	}
	void ButtonController::update(sf::RenderWindow & window)
	{
		if (timer.getElapsedTime().asSeconds() > 0.15f)
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
					if (this->buttons[activeIndex]->callback)
						this->buttons[activeIndex]->callback();
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
			if(this->buttons[activeIndex]->callback)
				this->buttons[activeIndex]->callback();
	}
	void ButtonController::render(sf::RenderTarget & target)
	{
		for (auto button : this->buttons)
		{
			button->render(target);
		}
	}
	void ButtonController::placeButtons(const sf::RenderWindow &window)
	{
		if (this->buttons.empty())
			return;

		const sf::Vector2f centerPos = sf::Vector2f(window.getSize()) / 2.f;

		sf::Vector2f startingPos(centerPos);

		int temp = this->buttons.size() / 2;
		float gap = 50.f;

		float offset = 0.f;
		if (this->buttons.size() % 2 != 0)
		{
			offset = temp * (this->buttons[0]->getSize().y + gap);
		}
		else
		{
			offset = temp * gap + (temp - 0.5f) * this->buttons[0]->getSize().y;
		}

		startingPos.y -= offset;

		for (int i = 0; i < this->buttons.size(); i++)
		{
			this->buttons[i]->setPosition(startingPos);
			startingPos.y += this->buttons[0]->getSize().y + gap;
		}
	}
}
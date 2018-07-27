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
	void ButtonController::addButton(Button * button)
	{
		this->buttons.push_back(button);
	}
	void ButtonController::removeButton()
	{
		this->buttons.pop_back();
	}
	void ButtonController::update(sf::RenderWindow & window)
	{
		// if there are any buttons
		if (this->buttons.empty())
			return;

		// if user holds the up/down arrow the buttons won't
		// scroll so fast
		if (timer.getElapsedTime().asSeconds() > 0.15f)
		{
			// check for keyboard input
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
			// if mouse hovers over a button
			if (this->buttons[i]->mouseOver(window))
			{
				// the button now is active
				this->activeIndex = i;
				// and if the mouse is pressed, perform an action
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
			// for all inactive buttons, make sure they're "turned off"
			if (this->activeIndex != i)
				this->buttons[i]->onUnhover();
		}

		// the active button is "turned on"
		this->buttons[activeIndex]->onHover();

		// check if user pressed an enter key rather than clicking on button
		// with the mouse
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
	void ButtonController::placeButtons(const sf::RenderWindow &window, float gap)
	{
		if (this->buttons.empty())
			return;

		const sf::Vector2f centerPos = sf::Vector2f(window.getSize()) / 2.f;

		sf::Vector2f startingPos(centerPos);

		// override the x coord if it was set eariler
		if (this->nonStandardPosition)
			startingPos.x = this->buttons[0]->getPosition().x;


		// tells how many buttons are above the center position
		// aswell as specifies the middle index of buttons vector
		int temp = this->buttons.size() / 2;

		// how much to move from the center y coord to the point where should be
		// center of the first button
		float offset = 0.f;

		// height of buttons ( now the function works with the buttons
		// that are the same height
		float buttonSizeY = this->buttons[0]->getSize().y;

		// set the offset accordingly to the number of buttons
		// being odd or even
		if (this->buttons.size() % 2 != 0)
			offset = temp * (buttonSizeY + gap);
		else
			offset = temp * gap + (temp - 0.5f) * buttonSizeY;

		startingPos.y -= offset;

		for (int i = 0; i < this->buttons.size(); i++)
		{
			this->buttons[i]->setPosition(startingPos);
			startingPos.y += buttonSizeY + gap;
		}
	}
	void ButtonController::setPositionX(float x)
	{
		this->map([x](Button* button) {
			button->setPosition(sf::Vector2f(x, button->getPosition().y));
		});

		this->nonStandardPosition = true;
	}
	void ButtonController::setButtonFixedSize(const sf::Vector2f & size)
	{
		this->map([&size](Button* button) {
			button->setSize(size);
		});
	}
	void ButtonController::map(const std::function<void(Button*)>& function)
	{
		std::for_each(this->buttons.begin(), this->buttons.end(), function);
	}
}
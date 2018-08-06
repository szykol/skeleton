#include "ButtonController.h"

namespace sen {
	ButtonController::ButtonController(const ButtonPointerVector& buttons)
		: m_buttons(buttons)
	{
	}
	ButtonController::ButtonController(const ButtonPointerVector& buttons, const sf::RenderWindow & window)
		: m_buttons(buttons)
	{
		placeButtons(window);
	}
	void ButtonController::pushButtons(ButtonPointer& button)
	{
		m_buttons.push_back(button);
	}
	
	void ButtonController::removeButton()
	{
		m_buttons.pop_back();
	}
	void ButtonController::update(sf::RenderWindow & window)
	{
		// if there are any buttons
		if (m_buttons.empty())
			return;

		// if user holds the up/down arrow the buttons won't
		// scroll so fast
		if (m_timer.getElapsedTime().asSeconds() > 0.15f)
		{
			// check for keyboard input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (m_activeIndex >= m_buttons.size() - 1)
					m_activeIndex = 0;
				else
					m_activeIndex++;
				m_timer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (m_activeIndex <= 0)
					m_activeIndex = m_buttons.size() - 1;
				else
					m_activeIndex--;
				m_timer.restart();
			}
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
			&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_canClick = true;
			}
		}

		for (int i = 0; i < m_buttons.size(); ++i)
		{
			// if mouse hovers over a button
			if (m_buttons[i]->mouseOver(window))
			{
				// the button now is active
				m_activeIndex = i;
				// and if the mouse is pressed, perform an action
				if (m_canClick && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					m_buttons[m_activeIndex]->onClick();
					if (m_buttons[m_activeIndex]->m_clickCallback)
					{
						m_buttons[m_activeIndex]->m_clickCallback();
						m_canClick = false;
					}
				}
			}
		}

		for (int i = 0; i < m_buttons.size(); ++i)
		{
			// for all inactive buttons, make sure they're "turned off"
			if (m_activeIndex != i)
				m_buttons[i]->onUnhover();
		}

		// the active button is "turned on"
		m_buttons[m_activeIndex]->onHover();

		// check if user pressed an enter key rather than clicking on button
		// with the mouse
		if (m_canClick && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			if (m_buttons[m_activeIndex]->m_clickCallback)
			{
				m_buttons[m_activeIndex]->onClick();
				m_buttons[m_activeIndex]->m_clickCallback();
				m_canClick = false;
			}
	}
	void ButtonController::render(sf::RenderTarget & target)
	{
		for (auto button : m_buttons)
		{
			button->render(target);
		}
	}
	void ButtonController::placeButtons(const sf::RenderWindow &window, float gap)
	{
		if (m_buttons.empty())
			return;

		const sf::Vector2f centerPos = sf::Vector2f(window.getSize()) / 2.f;

		sf::Vector2f startingPos(centerPos);

		// override the x coord if it was set eariler
		if (m_nonStandardPosition)
			startingPos.x = m_buttons[0]->getPosition().x;


		// tells how many buttons are above the center position
		// aswell as specifies the middle index of buttons vector
		int temp = m_buttons.size() / 2;

		// how much to move from the center y coord to the point where should be
		// center of the first button
		float offset = 0.f;

		// height of buttons ( now the function works with the buttons
		// that are the same height
		float buttonSizeY = m_buttons[0]->getSize().y;

		// set the offset accordingly to the number of buttons
		// being odd or even
		if (m_buttons.size() % 2 != 0)
			offset = temp * (buttonSizeY + gap);
		else
			offset = temp * gap + (temp - 0.5f) * buttonSizeY;

		startingPos.y -= offset;

		for (int i = 0; i < m_buttons.size(); i++)
		{
			m_buttons[i]->setPosition(startingPos);
			startingPos.y += buttonSizeY + gap;
		}
	}
	void ButtonController::setPositionX(float x)
	{
		map([x](ButtonPointer& button) {
			button->setPosition(sf::Vector2f(x, button->getPosition().y));
		});

		m_nonStandardPosition = true;
	}
	void ButtonController::setButtonFixedSize(const sf::Vector2f & size)
	{
		map([&size](ButtonPointer& button) {
			button->setSize(size);
		});
	}
	void ButtonController::map(const std::function<void(ButtonPointer&)>& function)
	{
		std::for_each(m_buttons.begin(), m_buttons.end(), function);
	}
	// void ButtonController::freeMemory()
	// {
	// 	for (auto b : m_buttons)
	// 		delete b;
	// }
}
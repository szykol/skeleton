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
		auto prev = sf::Keyboard::Up;
		auto next = sf::Keyboard::Down;

		if(m_buttonPlacing == ButtonPlacing::HORIZONTAL)
		{
			prev = sf::Keyboard::Left;
			next = sf::Keyboard::Right;
		}
		// if there are any buttons
		if (m_buttons.empty())
			return;

		// if user holds the up/down arrow the buttons won't
		// scroll so fast
		if (m_timer.getElapsedTime().asSeconds() > 0.15f)
		{
			// check for keyboard input
			if (sf::Keyboard::isKeyPressed(next))
			{
				if (m_activeIndex >= m_buttons.size() - 1)
					m_activeIndex = 0;
				else
					m_activeIndex++;
				m_timer.restart();
			}
			else if (sf::Keyboard::isKeyPressed(prev))
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
		sf::FloatRect bounds(0.f,0.f,window.getSize().x, window.getSize().y);
		placeButtons(bounds, gap);
	}
	void ButtonController::placeButtons(const sf::FloatRect& bounds, float gap)
	{
		if (m_buttons.empty())	return;

		// middle of the bounding box
		sf::Vector2f startingPos(
			bounds.left + bounds.width / 2.f,
			bounds.top + bounds.height / 2.f
		);
		
		// override the x coord if it was set eariler
		if (m_buttonPlacing==ButtonPlacing::VERTICAL && m_nonStandardPosition)
			startingPos.x = m_coord;
		else if(m_nonStandardPosition)
			startingPos.y = m_coord;

		// tells how many buttons are above the center position
		// aswell as specifies the middle index of buttons vector
		int temp = m_buttons.size() / 2;

		// how much to move from the center y coord to the point where should be
		// center of the first button
		float offset = 0.f;

		sf::Vector2f biggestSize = getBiggestSizeOfButton();
		float buttonSize = m_buttonPlacing == ButtonPlacing::VERTICAL ? biggestSize.y : biggestSize.x;
		checkIfSameSize(buttonSize);
		// set the offset accordingly to the number of buttons
		// being odd or even
		if (m_buttons.size() % 2 != 0)
			offset = temp * (buttonSize + gap);
		else
			offset = temp * gap + (temp - 0.5f) * buttonSize;
		
		

		if(m_buttonPlacing == ButtonPlacing::VERTICAL)
		{
			startingPos.y -= offset;
			if(m_baseline == ButtonBaseline::START)
				startingPos.x = bounds.left + biggestSize.x;
			else if(m_baseline == ButtonBaseline::END)
				startingPos.x = bounds.left + bounds.width - biggestSize.x;
		}
		else
		{
			startingPos.x -= offset;
			if(m_baseline == ButtonBaseline::START)
				startingPos.y = bounds.top + biggestSize.y;
			else if(m_baseline == ButtonBaseline::END)
				startingPos.y = bounds.top + bounds.height - biggestSize.y;
		}	

		for (int i = 0; i < m_buttons.size(); i++)
		{
			m_buttons[i]->setPosition(startingPos);
			if(m_buttonPlacing == ButtonPlacing::VERTICAL)
				startingPos.y += buttonSize + gap;
			else
				startingPos.x += buttonSize + gap;
		}
	}
	void ButtonController::setCoord(float coord)
	{
		m_coord = coord;
		m_nonStandardPosition = true;
	}
	void ButtonController::setOffset(float offset)
	{
		if(m_buttonPlacing == ButtonPlacing::HORIZONTAL)
			map(
			[offset](ButtonPointer& button) {
				button->move(0.f, offset);
			}
		);
		else
			map(
			[offset](ButtonPointer& button) {
				button->move(offset, 0.f);
			}
		);

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
	sf::Vector2f ButtonController::getBiggestSizeOfButton()
	{
		sf::Vector2f biggestSize(0.f,0.f);
		map(
			[&biggestSize](ButtonPointer& b) {
				if(b->getSize().x * b->getSize().y >
					biggestSize.x * biggestSize.y)
					biggestSize = b->getSize();
			}
		);
		return biggestSize;
	}
	void ButtonController::checkIfSameSize(float biggestSize)
	{
		if (m_sameSize)
		{
			if (m_buttonPlacing == ButtonPlacing::VERTICAL)
			{
				map(
					[&biggestSize](ButtonPointer b) {
					b->setSize({ b->getSize().x , biggestSize});
					}
				);
			}
			else
				map(
					[&biggestSize](ButtonPointer b) {
					b->setSize({ biggestSize, b->getSize().y});
					}
				);
		}
	}
}
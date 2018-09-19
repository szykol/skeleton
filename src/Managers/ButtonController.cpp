#include "ButtonController.h"

#include "../Application.h"

namespace sen {
	ButtonController::ButtonController(const ButtonPointerVector& buttons)
		: m_buttons(buttons)
	{
		placeButtons();
	}
	void ButtonController::pushButtons(ButtonPointer& button)
	{
		m_buttons.push_back(button);
	}
	
	void ButtonController::removeButton()
	{
		m_buttons.pop_back();
	}
	void ButtonController::update(float deltaTime)
	{
		enum ButtonMovement { DOWN = -1, NONE = 0, UP = 1};
		auto movement = int{ ButtonMovement::NONE };

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
		m_time += deltaTime;

		float timeSwitch = 0.2f;

		if (m_time > timeSwitch)
		{
			// check for keyboard input
			if (sf::Keyboard::isKeyPressed(next))
			{
				if (m_activeIndex >= m_buttons.size() - 1)
				{
					if (!m_canScroll)
						m_activeIndex = 0;
				}
				else
				{
					m_activeIndex++;
					if (m_canScroll)
					{
						movement = ButtonMovement::DOWN;
					}
				}
				m_time = 0.f;
			}
			else if (sf::Keyboard::isKeyPressed(prev))
			{
				if (m_activeIndex <= 0)
				{
					if (!m_canScroll)
						m_activeIndex = m_buttons.size() - 1;
				}
				else
				{
					m_activeIndex--;
					if (m_canScroll)
					{
						movement = ButtonMovement::UP;
					}
				}
				m_time = 0.f;
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
			if (m_buttons[i]->mouseOver())
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

		if (movement != ButtonMovement::NONE)
		{
			float jump = m_jumpOffset * movement;

			if(m_buttonPlacing == ButtonPlacing::VERTICAL)
			map(
				[jump](Button* b)
				{
					b->setPosition({ b->getPosition().x, b->getPosition().y + jump }, 6.3f);
				}
			);
			else
			map(
				[jump](Button* b)
				{
					b->setPosition({b->getPosition().x + jump, b->getPosition().y }, 6.3f);
				}
			);
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
	void ButtonController::placeButtons(float gap)
	{
		sf::FloatRect bounds(0.f,0.f,Application::getInitialWindowSize().x, Application::getInitialWindowSize().y);
		placeButtons(bounds, gap);
	}
	void ButtonController::placeButtons(const sf::FloatRect& bounds, float gap)
	{
		if (m_buttons.empty())	return;

		// middle of the bounding box
		sf::Vector2f center(
			bounds.left + bounds.width / 2.f,
			bounds.top + bounds.height / 2.f
		);
		
		auto startingPos = center;

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
			offset = (temp - 0.5f) * (buttonSize + gap);
		
		

		if(m_buttonPlacing == ButtonPlacing::VERTICAL)
		{
			startingPos.y -= offset;

			if (startingPos.y - buttonSize / 2.f < bounds.top)
				m_canScroll = true;

			if(m_baseline == ButtonBaseline::START)
				startingPos.x = bounds.left + biggestSize.x;
			else if(m_baseline == ButtonBaseline::END)
				startingPos.x = bounds.left + bounds.width - biggestSize.x;
		}
		else
		{
			startingPos.x -= offset;

			if (startingPos.x - buttonSize / 2.f < bounds.left)
				m_canScroll = true;

			if(m_baseline == ButtonBaseline::START)
				startingPos.y = bounds.top + biggestSize.y;
			else if(m_baseline == ButtonBaseline::END)
				startingPos.y = bounds.top + bounds.height - biggestSize.y;
		}	

		if (m_canScroll)
		{
			if (m_buttonPlacing == ButtonPlacing::VERTICAL)
				startingPos.y = center.y;
			else
				startingPos.x = center.x;
		}
		
		for (int i = 0; i < m_buttons.size(); i++)
		{
			m_buttons[i]->setPosition(startingPos);
			if(m_buttonPlacing == ButtonPlacing::VERTICAL)
				startingPos.y += buttonSize + gap;
			else
				startingPos.x += buttonSize + gap;
		}

		m_jumpOffset = buttonSize + gap;
	}
	void ButtonController::setCoord(float coord)
	{
		m_coord = coord;
		m_nonStandardPosition = true;
	}
	void ButtonController::setOffset(float offset, float speed)
	{
		if (m_buttonPlacing == ButtonPlacing::HORIZONTAL)
		{
			if (m_buttons.size() > 0)
			{
				auto goToPos = m_buttons[0]->getPosition().y + offset;
					map(
						[=](Button* button) {
					button->setPosition(button->getPosition().x, goToPos, speed);
				}
				);
			}
		}
		else
		{
			if (m_buttons.size() > 0)
			{
				auto goToPos = m_buttons[0]->getPosition().x + offset;

			map(
				[=](Button* button) {
				button->setPosition(goToPos, button->getPosition().y, speed);
			}
			);
			}
		}
	}
	void ButtonController::setButtonFixedSize(const sf::Vector2f & size)
	{
		map([&size](Button* button) {
			button->setSize(size);
		});
	}

	void ButtonController::map(const std::function<void(Button*)>& function)
	{
		std::for_each(m_buttons.begin(), m_buttons.end(), [&](const std::shared_ptr<Button>& ptr) {
			function(ptr.get());
		});
	}
	sf::Vector2f ButtonController::getBiggestSizeOfButton()
	{
		sf::Vector2f biggestSize(0.f,0.f);
		map(
			[&biggestSize](Button* b) {
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
					[&biggestSize](Button* b) {
					b->setSize({ b->getSize().x , biggestSize});
					}
				);
			}
			else
				map(
					[&biggestSize](Button* b) {
					b->setSize({ biggestSize, b->getSize().y});
					}
				);
		}
	}
}
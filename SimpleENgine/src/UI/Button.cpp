#include "Button.h"

namespace sen {
	void Button::onHover()
	{
        const ButtonAction* action = getCallbackForState(ButtonEvent::HOVER);

        if(!action || !action->second)
        {
            setFillColor(sf::Color(sf::Color(25, 25, 25, 50)));
            setOutlineColor(sf::Color(222, 222, 222, 240));
            m_message.setFillColor(getOutlineColor());
        }
        if(action) action->first(*this);
	}
	void Button::onUnhover()
	{
        const ButtonAction* action = getCallbackForState(ButtonEvent::STANDARD);
        
        if(!action || !action->second)
        {
            setFillColor(sf::Color(25, 25, 25, 170));
            setOutlineColor(sf::Color(222, 222, 222, 170));
            m_message.setFillColor(Box::getOutlineColor());
        }
        if(action) action->first(*this);

		m_message.setString(m_standardString);
	}
	void Button::onClick()
	{
        const ButtonAction* action = getCallbackForState(ButtonEvent::CLICK);
        
        if(!action || !action->second)
        {
            setOutlineColor(sf::Color(0, 198, 0, 190));
            m_message.setFillColor(Box::getOutlineColor());
        }
        if(action) action->first(*this);
	}
	void Button::update(sf::RenderWindow & window)
	{
        // create a cooldown to avoid calling the callback function every frame
		if (m_timer.getElapsedTime().asSeconds() > 0.5f
			&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			clickable = true;
			m_timer.restart();
		}

		if (mouseOver(window))
		{
			if (clickable && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				onClick();
				if (m_clickCallback)
					m_clickCallback();
				clickable = false;
			}
			else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
				onHover();
		}
		else
			onUnhover();
	}
	bool Button::mouseOver(const sf::RenderWindow & window)
	{
        // get position of mouse
		const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		// return whether the mouse is in bounds of button
		return (getGlobalBounds().contains(mousePos));
	}
	void Button::addListener(ButtonEvent state, 
        const Callback & callback, bool preventDefault)
	{
        if(!m_callbacks)
            m_callbacks = new CallbackMap();
        
        ButtonAction action = std::make_pair(callback, preventDefault);
        // if there is a listener already, delete it
        if(m_callbacks->find(state) != m_callbacks->end())
            m_callbacks->erase(state);
        m_callbacks->insert(std::make_pair(state,action));
	}
	Button::~Button()
	{
        if(m_callbacks)
            delete m_callbacks;
	}
	const ButtonAction* Button::getCallbackForState(ButtonEvent state) const
	{
		if(!m_callbacks) return nullptr;

        if(m_callbacks->find(state) != m_callbacks->end())
        {
            return &m_callbacks->at(state);
        }
	}
}
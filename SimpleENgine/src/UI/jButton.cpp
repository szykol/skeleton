#include "jButton.h"

namespace sen {
    json jButton::s_globalSettings = {
        {"hover",{
            {"CharacterSize", 32U},
            {"FillColor", "Red"}
        }},
        {"click",{
            {"CharacterSize", 34U},
            {"FillColor", "White"}
        }}
    };
	void jButton::onHover()
	{
		setFillColor(sf::Color(sf::Color(25, 25, 25, 50)));
		setOutlineColor(sf::Color(222, 222, 222, 240));
		m_message.setFillColor(getOutlineColor());
	}
	void jButton::onUnhover()
	{
		setFillColor(sf::Color(25, 25, 25, 170));
		setOutlineColor(sf::Color(222, 222, 222, 170));
		m_message.setFillColor(Box::getOutlineColor());
	}
	void jButton::onClick()
	{
		setOutlineColor(sf::Color(0, 198, 0, 190));
		m_message.setFillColor(Box::getOutlineColor());
	}
	void jButton::update(sf::RenderWindow & window)
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
			onHover();
			if (clickable && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				onClick();
				if (m_callback)
					m_callback();
				clickable = false;
			}
		}
		else
			onUnhover();
	}
	bool jButton::mouseOver(const sf::RenderWindow & window)
	{
		// get position of mouse
		const sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		// return whether the mouse is in bounds of jButton
		return (getGlobalBounds().contains(mousePos));
	}
    void jButton::printGlobalSettings()
    {
        std::cout<<s_globalSettings<<std::endl;
        std::cout<<"json['hover']['FillColor']="<<s_globalSettings["hover"]["FillColor"]<<std::endl;


    }
}
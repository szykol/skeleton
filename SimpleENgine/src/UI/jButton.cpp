#include "jButton.h"
#include "../Util/sf_to_json.h"
#include "Text.h"
namespace sen {
    json jButton::s_globalSettings = {
        {"hover",{
            {"CharacterSize", 32U},
            {"FillColor", sf::Color::Red}
        }},
        {"click",{
            {"CharacterSize", 34U},
            {"FillColor", sf::Color::White}
        }},
		{"standard", {
			{"CharacterSize", 25U},
			{"FillColor", sf::Color(128,128,90,20)}
		}}
    };
	void jButton::onHover()
	{
		sf::Color color = s_globalSettings["hover"]["FillColor"];
		setFillColor(color);
	}
	void jButton::onUnhover()
	{
		sf::Color color = s_globalSettings["standard"]["FillColor"];
		setFillColor(color);
	}
	void jButton::onClick()
	{
		sf::Color color = s_globalSettings["click"]["FillColor"];
		setFillColor(color);
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
			
			if (clickable && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				onClick();
				if (m_callback)
					m_callback();
				clickable = false;
			}
			else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
				onHover();
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
    }
}
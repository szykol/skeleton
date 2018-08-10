#include "Popup.h"

namespace sen {
	Popup::Popup(const sf::RenderWindow & window, const sf::String & string,
		PopupBaseline baseline, float duration)
		:TextBox(string), m_duration(duration)
	{
        setSize(sf::Vector2f(window.getSize().x - 50.f, getSize().y * 2));
		if (baseline == PopupBaseline::BOTTOM)
            setPosition(sf::Vector2f(window.getSize().x / 2.f, window.getSize().y - getSize().y / 2.f));
        else
            setPosition(sf::Vector2f(window.getSize().x / 2.f, getSize().y / 2.f));
	}
	bool Popup::shouldVanish()
	{
        if(m_timer.getElapsedTime().asSeconds() > m_duration)
		{
			m_timer.restart();
			return true;
        }   
		return false;
	}
}
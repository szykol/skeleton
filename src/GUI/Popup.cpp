#include "Popup.h"
#include "../Managers/AnimationController.h"

#include "../Application.h"

namespace sen {
	Popup::Popup(const sf::String & string,
		PopupBaseline baseline, float duration)
		:TextBox(string), m_duration(duration)
	{
		setSize(sf::Vector2f(Application::getInitialWindowSize().x -50.f, getSize().y * 2));
		float yPos;
		if (baseline == PopupBaseline::BOTTOM)
		{
			setPosition(sf::Vector2f(Application::getInitialWindowSize().x / 2.f, Application::getInitialWindowSize().y + getSize().y / 2.f));
			yPos = Application::getInitialWindowSize().y - getSize().y / 2.f + 10.f;
		}
		else
		{
			setPosition(sf::Vector2f(Application::getInitialWindowSize().x / 2.f, -getSize().y / 2.f));
			yPos = getSize().y - 10.f;
		}

		setPosition(sf::Vector2f(Application::getInitialWindowSize().x / 2.f, yPos), 2.35f);
		//AnimationController::add(this, sf::Vector2f(Application::getInitialWindowSize().x / 2.f, yPos), 0.35f);
		//AnimationController::add(&m_message, sf::Vector2f(Application::getInitialWindowSize().x / 2.f, yPos), 0.35f);
	}
	bool Popup::shouldVanish(float deltaTime)
	{
		m_time += deltaTime;
        if(m_time > m_duration)
		{
			m_time = 0.f;
			return true;
        }   
		return false;
	}
}
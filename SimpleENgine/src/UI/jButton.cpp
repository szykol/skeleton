#include "jButton.h"
#include "Text.h"
#include "../Util/sf_to_json.h"

namespace sen {
    json jButton::s_globalSettings = {
        {"hover",{
            {"FillColor", sf::Color(25,25,25,50)},
            {"OutlineColor", sf::Color(222,222,222,240)},
			{"TextFillColor", sf::Color(222,222,222,240)}
        }},
        {"standard",{
            {"FillColor", sf::Color(25,25,25,170)},
            {"OutlineColor", sf::Color(222,222,222,170)},
			{"TextFillColor", sf::Color(222,222,222,170)}
        }},
		{"click", {
			{"OutlineColor", sf::Color(0,198,0,190)},
			{"TextFillColor", sf::Color(0,198,0,190)}
		}}
    };
	void jButton::onHover()
	{
		parseSettings("hover");
	}
	void jButton::onUnhover()
	{
		parseSettings("standard");
	}
	void jButton::onClick()
	{
		parseSettings("click");
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
	void jButton::parseSettings(const std::string& mode)
	{
		if(s_globalSettings.find(mode) == s_globalSettings.end())
			return;

		std::vector<const json*> settings;
		settings.push_back(&s_globalSettings[mode]);

		if(m_jsonSettings)
		{
			if(m_jsonSettings->find(mode) != m_jsonSettings->end())
				settings.push_back(&m_jsonSettings->at(mode));
		}

		for(const auto& setting: settings)
		{
			if(setting->find("Position") != setting->end())
			{
				setPosition(setting->at("Position"));
			}
			if(setting->find("FillColor") != setting->end())
			{
				setFillColor(setting->at("FillColor"));
			}
			if(setting->find("CharacterSize") != setting->end())
			{
				m_message.setCharacterSize(setting->at("CharacterSize"));
			}
			if(setting->find("OutlineColor") != setting->end())
			{
				setOutlineColor(setting->at("OutlineColor"));
			}
			if(setting->find("TextFillColor") != setting->end())
			{
				m_message.setFillColor(setting->at("TextFillColor"));
			}
			if(setting->find("TextString") != setting->end())
			{
				std::string tempString = setting->at("TextString");
				m_message.setString(tempString);
			}
		}
	}
	void jButton::setJSONSettings(const json& settings)
	{
		if(m_jsonSettings)
			delete m_jsonSettings;
		m_jsonSettings = new json();
		*m_jsonSettings = settings;
	}
	void jButton::removeJSONSettings()
	{
		if(m_jsonSettings)
			delete m_jsonSettings;
	}
}
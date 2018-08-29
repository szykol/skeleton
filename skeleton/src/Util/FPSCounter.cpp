#include "FPSCounter.h"

namespace sen {
	FPSCounter::FPSCounter()
		:Text("0.0"), m_fpsAmmount(0.f), m_elapsedTime(0.f),
		 m_updateDelay(0.15f)
	{
		Text::setOriginMode(sen::OriginMode::TOPLEFT);
		Text::setPosition({ 3.f, 3.f });
		Text::setCharacterSize(24U);
	}
	void FPSCounter::update(float deltaTime)
	{
		m_elapsedTime += deltaTime;
		if (m_elapsedTime > m_updateDelay)
		{
			m_fpsAmmount = 1.0f / deltaTime;
			std::string tempString = std::to_string(m_fpsAmmount);

			// ##.## (or #.##) format
			auto pos = tempString.find('.');
			tempString = tempString.erase(pos + 3);

			Text::setString(tempString);
			m_elapsedTime = 0.f;
		}
	}
	void FPSCounter::render(sf::RenderTarget & target)
	{
		Text::render(target);
	}
}
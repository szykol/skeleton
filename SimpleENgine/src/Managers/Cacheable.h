#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <chrono>
#include <iostream>

namespace sen {
	using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
	template<typename T>
	class Cacheable
	{
	private:
		TimePoint m_lastAccessed;
		bool init = true;
		std::shared_ptr<T> m_instance;
	public:
		Cacheable(const std::string& pathFile)
		{
			Load<T>(pathFile);
		}
		const std::shared_ptr<T>& getInstance()
		{
			m_lastAccessed = std::chrono::system_clock::now();
			init = false;
			return m_instance;
		}
		template<typename T>
		void Load(const std::string& pathFile)
		{
			m_instance = std::make_shared<T>();
			if (!m_instance->loadFromFile(pathFile))
				m_instance = nullptr;
		}
		template<>
		void Load<sf::Music>(const std::string& pathFile)
		{
			m_instance = std::make_shared<sf::Music>();
			if (!m_instance->openFromFile(pathFile))
				m_instance = nullptr;
		}
		bool shouldRemove()
		{
			auto now = std::chrono::system_clock::now();
			if (init && m_instance.use_count() > 1)
			{
				m_lastAccessed = now;
				return false;
			}

			std::chrono::duration<float> timePassed = now - m_lastAccessed;

			return (timePassed.count() > 60.f && m_instance.use_count() < 2);
		}
	};
}
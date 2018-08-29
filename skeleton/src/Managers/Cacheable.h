#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <chrono>
#include <iostream>

namespace sen {
	using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
	/** 
	 * @brief  Basic class that remembers when
	 * it was last acessed and is able to
	 * decide if it can be removed from memory
	 * @note   Used with CacheSystem
	 */
	template<typename T>
	class Cacheable
	{
	private:
		TimePoint m_lastAccessed;
		bool init = true;
		std::shared_ptr<T> m_instance;
	public:
		/** 
		 * @brief  Loads an instance from file
		 * @param  pathFile: path to file
		 */
		Cacheable(const std::string& pathFile)
		{
			Load<T>(pathFile);
		}
		/** 
		 * @brief  Returns a shared_ptr to the
		 * instance and remembers when it was 
		 * last accessed
		 * @retval shared_ptr to an instance
		 */
		const std::shared_ptr<T>& getInstance()
		{
			m_lastAccessed = std::chrono::system_clock::now();
			init = false;
			return m_instance;
		}
		/** 
		 * @brief  Template for sf objects that 
		 * can be loaded from file
		 * @param  pathFile: path to file
		 * @retval None
		 */
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
		/** 
		 * @brief  If there's no other shared_ptr
		 * holding an instance that's kept in this
		 * object and 3 minutes have passed the object
		 * can be removed
		 */
		bool shouldRemove()
		{
			auto now = std::chrono::system_clock::now();
			if (init && m_instance.use_count() > 1)
			{
				m_lastAccessed = now;
				return false;
			}

			std::chrono::duration<float> timePassed = now - m_lastAccessed;

			return (timePassed.count() > 3*60.f && m_instance.use_count() < 2);
		}
	};
}
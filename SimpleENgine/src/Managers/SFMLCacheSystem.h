#pragma once

#include <unordered_map>

#include "Cacheable.h"

#include <SFML/Graphics.hpp>

namespace sen {
	/** 
	 * @brief  Keeps track of sfml objects that can be loaded
	 * from files. It introduces simple cache management that
	 * will be responsible for removing no longer used 
	 * objects from memory
	 * @note   It's used for implementation of the engine
	 */
	class SFMLCacheSystem
	{
	private:
		std::unordered_map<std::string, Cacheable<sf::Font>> m_fonts;
		std::unordered_map<std::string, Cacheable<sf::Texture>> m_textures;
		std::unordered_map<std::string, Cacheable<sf::Music>> m_music;
		std::unordered_map<std::string, Cacheable<sf::SoundBuffer>> m_soundBuffers;
		sf::Clock m_timer;
	public:
		/** 
		 * @brief  tries to locate an object
		 * in memory, if it's not there it will
		 * try to load the object from file
		 * @note   Can return nullptr
		 * @param  pathFile: path to file
		 * @retval 
		 */
		template<typename T>
		std::shared_ptr<T> get(const std::string& pathFile)
		{
			auto& map = getMap<T>();
			auto find = map.find(pathFile);
			if (find != map.end())
				return find->second.getInstance();

			Cacheable<T> newInstance(pathFile);
			auto instance = newInstance.getInstance();
			map.insert({ pathFile, newInstance });

			// check if some cache needs to be deleted
			// if cache system is heavily used this makes
			// sure that update doesn't happen everytime
			// user gets something from it 
			if(m_timer.getElapsedTime().asSeconds() > 30.f)
			{
				update();
				m_timer.restart();
			}
			return instance;	
		}
	private:
		template<typename T>
		std::unordered_map<std::string, Cacheable<T>>& getMap()
		{
			static_assert(false);
		}
		template<>
		std::unordered_map<std::string, Cacheable<sf::Font>>& getMap<sf::Font>()
		{
			return m_fonts;
		}
		template<>
		std::unordered_map<std::string, Cacheable<sf::Texture>>& getMap<sf::Texture>()
		{
			return m_textures;
		}
		template<>
		std::unordered_map<std::string, Cacheable<sf::Music>>& getMap<sf::Music>()
		{
			return m_music;
		}
		template<>
		std::unordered_map<std::string, Cacheable<sf::SoundBuffer>>& getMap<sf::SoundBuffer>()
		{
			return m_soundBuffers;
		}
		/** 
		 * @brief  Checks for music and soundbuffer objects
		 * that need to be removed from memory
		 */
		void update();
	};
	
}
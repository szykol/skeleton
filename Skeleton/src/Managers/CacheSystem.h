#pragma once

#include <unordered_map>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

namespace sen {
		/**
	 * @brief  Loads an sfml type from file and 
	 * returns a shared_ptr to it
	 * @param  pathFile: path to file 
	 */
	template<typename T>
	std::shared_ptr<T> loadFromFile(const std::string& pathFile) = delete;
	

	template<>
	inline std::shared_ptr<sf::Font> loadFromFile<sf::Font>(const std::string& pathFile)
	{
		auto font = std::make_shared<sf::Font>();
		if (!font->loadFromFile(pathFile))
			return nullptr;
		return font;
	}

	template<>
	inline std::shared_ptr<sf::Texture> loadFromFile<sf::Texture>(const std::string& pathFile)
	{
		auto tex = std::make_shared<sf::Texture>();
		if (!tex->loadFromFile(pathFile))
			return nullptr;
		return tex;
	}

	template<>
	inline std::shared_ptr<sf::SoundBuffer> loadFromFile<sf::SoundBuffer>(const std::string& pathFile)
	{
		auto sb = std::make_shared<sf::SoundBuffer>();
		if (!sb->loadFromFile(pathFile))
			return nullptr;
		return sb;
	}

	template<>
	inline std::shared_ptr<sf::Music> loadFromFile<sf::Music>(const std::string& pathFile)
	{
		auto mus = std::make_shared<sf::Music>();
		if (!mus->openFromFile(pathFile))
			return nullptr;
		return mus;
	}

	template<typename T>
	using CacheMap = std::unordered_map<std::string, std::weak_ptr<T>>;

	class CacheSystem
	{
		static CacheMap<sf::Font> m_fonts;
		static CacheMap<sf::Texture> m_textures;
		static CacheMap<sf::Music> m_music;
		static CacheMap<sf::SoundBuffer> m_soundBuffers;

		static float s_time;
		static float s_updateTime;
	public:
		/**
		 * @brief  Returns an instance of either
		 * sf::SoundBuffer, sf::Texture, sf::Font,
		 * sf::Music loaded from file. Those instances 
		 * are cached which means you need to keep at least
		 * one shared_ptr to the object you want to access.
		 * Otherwise it will be deleted from memory.
		 * @note   if the object cannot be loaded from file
		 * it returns nullptr.
		 * @param  pathFile: a path to file
		 * @retval 
		 */
		template<typename T>
		static std::shared_ptr<T> get(const std::string& pathFile)
		{
			auto& map = getMap<T>();

			auto ptr = map[pathFile].lock();
			if (!ptr)
			{
				ptr = loadFromFile<T>(pathFile);
				map[pathFile] = ptr;
			}

			return ptr;
		}

		/**
		 * @brief  Removes all weak_ptrs to the object that
		 * are not longer used and frees the memory they were
		 * holding
		 */
		static void update(float deltaTime);
	private:

		/**
		 * @brief  Helper method that updates the map 
		 * and removes all weak_ptrs
		 */
		template<typename T>
		static void updateMap(CacheMap<T>& map)
		{
			for (auto weak = map.cbegin(); weak != map.cend();)
			{
				if (weak->second.expired())
				{
					weak = map.erase(weak);
				}
				else
					++weak;
			}
		}

		/**
		 * @brief  Returns a map according to a type
		 */
		template<typename T>
		static CacheMap<T>& getMap() = delete;
		
	};

	template<>
	inline CacheMap<sf::Font>& CacheSystem::getMap()
	{
		return m_fonts;
	}

	template<>
	inline CacheMap<sf::Texture>& CacheSystem::getMap()
	{
		return m_textures;
	}

	template<>
	inline CacheMap<sf::SoundBuffer>& CacheSystem::getMap()
	{
		return m_soundBuffers;
	}

	template<>
	inline CacheMap<sf::Music>& CacheSystem::getMap()
	{
		return m_music;
	}
}
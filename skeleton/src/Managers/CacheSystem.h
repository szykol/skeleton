#pragma once

#include <unordered_map>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

namespace sen {
	
	template<typename T>
	using CacheMap = std::unordered_map<std::string, std::weak_ptr<T>>;

	class CacheSystem
	{
		static CacheMap<sf::Font> m_fonts;
		static CacheMap<sf::Texture> m_textures;
		static CacheMap<sf::Music> m_music;
		static CacheMap<sf::SoundBuffer> m_soundBuffers;

		// TODO: Remove all weak ptrs from memory (if they're empty)
		/*float s_time = 0.f;
		float s_updateTime = 10.f;*/
	public:
		template<typename T>
		static std::shared_ptr<T> get(const std::string& pathFile)
		{
			auto& map = getMap<T>();

			auto ptr = map[pathFile].lock();
			if (!ptr)
			{
				std::cout << "Loading a new instance\n"; 
				ptr = loadFromFile<T>(pathFile);
				map[pathFile] = ptr;
			}

			return ptr;
		}
	private:
		template<typename T>
		static CacheMap<T>& getMap()
		{
			static_assert(false);
		}

		template<>
		static CacheMap<sf::Font>& getMap<sf::Font>()
		{
			return m_fonts;
		}

		template<>
		static CacheMap<sf::Texture>& getMap<sf::Texture>()
		{
			return m_textures;
		}

		template<>
		static CacheMap<sf::SoundBuffer>& getMap<sf::SoundBuffer>()
		{
			return m_soundBuffers;
		}

		template<>
		static CacheMap<sf::Music>& getMap<sf::Music>()
		{
			return m_music;
		}

	};

	template<typename T>
	inline std::shared_ptr<T> loadFromFile(const std::string& pathFile)
	{
		static_assert(false);
	}

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
}
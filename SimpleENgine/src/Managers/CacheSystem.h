#pragma once

#include <unordered_map>

#include "Cacheable.h"

#include <SFML/Graphics.hpp>

namespace sen {
	class CacheSystem
	{
	private:
		std::unordered_map<std::string, Cacheable<sf::Font>> m_fonts;
		std::unordered_map<std::string, Cacheable<sf::Texture>> m_textures;
		std::unordered_map<std::string, Cacheable<sf::Music>> m_music;
		std::unordered_map<std::string, Cacheable<sf::SoundBuffer>> m_soundBuffers;
		sf::Clock m_timer;
	public:
		std::shared_ptr<sf::Font> getFont(const std::string& pathFile);
		std::shared_ptr<sf::Texture> getTexture(const std::string& pathFile);
		std::shared_ptr<sf::Music> getMusic(const std::string& pathFile);
		std::shared_ptr<sf::SoundBuffer> getSoundBuffer(const std::string& pathFile);
		void update();
	};
	
}
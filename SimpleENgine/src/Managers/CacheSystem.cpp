#include "CacheSystem.h"

#include <iostream>

namespace sen {
	std::shared_ptr<sf::Font> CacheSystem::getFont(const std::string & pathFile)
	{
		auto find = m_fonts.find(pathFile);
		if (find != m_fonts.end())
			return find->second.getInstance();

		Cacheable<sf::Font> newFont(pathFile);
		auto instance = newFont.getInstance();
		m_fonts.insert({ pathFile, newFont });
		return instance;
	}
	std::shared_ptr<sf::Texture> CacheSystem::getTexture(const std::string & pathFile)
	{
		auto find = m_textures.find(pathFile);
		if (find != m_textures.end())
			return find->second.getInstance();

		Cacheable<sf::Texture> newTexture(pathFile);
		m_textures.insert({ pathFile, newTexture });
		return newTexture.getInstance();
	}
	std::shared_ptr<sf::Music> CacheSystem::getMusic(const std::string & pathFile)
	{
		auto find = m_music.find(pathFile);
		if (find != m_music.end())
			return find->second.getInstance();

		Cacheable<sf::Music> newMusic(pathFile);
		m_music.insert({ pathFile, newMusic });
		return newMusic.getInstance();
	}
	std::shared_ptr<sf::SoundBuffer> CacheSystem::getSoundBuffer(const std::string & pathFile)
	{
		auto find = m_soundBuffers.find(pathFile);
		if (find != m_soundBuffers.end())
			return find->second.getInstance();

		Cacheable<sf::SoundBuffer> newSoundBuffer(pathFile);
		m_soundBuffers.insert({ pathFile, newSoundBuffer });
		return newSoundBuffer.getInstance();
	}
	void CacheSystem::update()
	{
		if (m_fonts.empty()) return;
		for (auto it = m_fonts.begin(); it != m_fonts.end(); it++)
		{
			if (it->second.shouldRemove())
			{
				m_fonts.erase(it);
				break;
			}
		}
		
	}
}
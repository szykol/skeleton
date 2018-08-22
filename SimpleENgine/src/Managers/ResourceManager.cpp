#include "ResourceManager.h"

namespace sen {
	ResourceManager::ResourceManager()
        : m_audioProvider(m_cache)
	{
		
	}
	const sf::Font& ResourceManager::getFont(const std::string & pathFile)
	{
        return *m_cache.get<sf::Font>(pathFile);
	}
	const sf::Texture & ResourceManager::getTexture(const std::string & pathFile)
	{
        return *m_cache.get<sf::Texture>(pathFile);
	}
}
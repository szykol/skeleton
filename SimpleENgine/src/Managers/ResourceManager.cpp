#include "ResourceManager.h"

namespace sen {
	SFMLCacheSystem ResourceManager::m_cache;
	SFMLAudioProvider ResourceManager::m_audioProvider(ResourceManager::m_cache);
	const sf::Font& ResourceManager::getFont(const std::string & pathFile)
	{
		return *m_cache.get<sf::Font>(pathFile);
	}
	const sf::Texture & ResourceManager::getTexture(const std::string & pathFile)
	{
		return *m_cache.get<sf::Texture>(pathFile);
	}
}
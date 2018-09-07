#include "CacheSystem.h"

namespace sen {
	CacheMap<sf::Font> CacheSystem::m_fonts;
	CacheMap<sf::Texture> CacheSystem::m_textures;
	CacheMap<sf::Music> CacheSystem::m_music;
	CacheMap<sf::SoundBuffer> CacheSystem::m_soundBuffers;
}
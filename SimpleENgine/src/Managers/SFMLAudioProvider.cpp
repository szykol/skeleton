#include "SFMLAudioProvider.h"

namespace sen {
	SFMLAudioProvider::SFMLAudioProvider(SFMLCacheSystem & cache)
		: m_cache(cache)
	{
	}
	void SFMLAudioProvider::playSound(const std::string & pathFile)
	{
		auto sbf = m_cache.get<sf::SoundBuffer>(pathFile);
		sf::SoundBuffer& sbfr = *sbf;
		m_currentSound = std::make_shared<sf::Sound>(sbfr);
		m_currentSound->play();
	}
	void SFMLAudioProvider::playMusic(const std::string & pathFile)
	{
		if(m_currentMusic && m_currentMusic->getStatus() != sf::Music::Stopped)
			m_currentMusic->stop();
		
		m_currentMusic = m_cache.get<sf::Music>(pathFile);
		if(m_currentMusic)
			m_currentMusic->play();
	}
	void SFMLAudioProvider::setVolume(int vol)
	{
		if(m_currentMusic)
			m_currentMusic->setVolume(vol);
	}
}
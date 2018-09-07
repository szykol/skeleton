#include "SFMLAudioProvider.h"

#include "CacheSystem.h"

namespace sen {
	void SFMLAudioProvider::playSound(const std::string & pathFile)
	{
		auto sbf = CacheSystem::get<sf::SoundBuffer>(pathFile);
		if(sbf)
		{
			m_currentSound = std::make_shared<sf::Sound>(*sbf);
			m_currentSound->play();
		}
	}
	void SFMLAudioProvider::playMusic(const std::string & pathFile, bool looping)
	{
		if(m_currentMusic && m_currentMusic->getStatus() != sf::Music::Stopped)
			m_currentMusic->stop();
		
		m_currentMusic = CacheSystem::get<sf::Music>(pathFile);
		if(m_currentMusic)
		{
			m_currentMusic->setLoop(looping);
			m_currentMusic->play();
		}
	}
	void SFMLAudioProvider::setVolume(int vol)
	{
		if(m_currentMusic)
			m_currentMusic->setVolume(vol);
	}
}
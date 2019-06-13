#include "SFMLAudioProvider.h"

#include "CacheSystem.h"

namespace sen {
	void SFMLAudioProvider::playSound(const std::string & pathFile)
	{
		auto sbf = CacheSystem::get<sf::SoundBuffer>(pathFile);

		auto shouldInsert = true;
		for (auto&x : m_buffers)
		{
			if (x.get() == sbf.get())
			{
				shouldInsert = false;
				break;
			}
		}
		
		if (shouldInsert)
			m_buffers.emplace_back(sbf);

		if (sbf)
		{
			m_sounds.emplace_back(*sbf);
			m_sounds.back().play();
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
	void SFMLAudioProvider::update(float deltaTime)
	{
		m_time += deltaTime;

		if (m_time > m_updateTime)
		{
			m_time -= m_updateTime;

			for (auto bf = m_buffers.begin(); bf != m_buffers.end();)
			{
				auto shouldDelete = true;
				for (auto sound = m_sounds.begin(); sound != m_sounds.end(); )
				{
					// if sound is playing
					if (sound->getStatus() == sf::Sound::Playing)
					{
						// and it has a buffer we are currently
						// checking, buffer shouldn't be deleted
						if (sound->getBuffer() == bf->get())
							shouldDelete = false;
						++sound;
					} // else erase sound
					else
						sound = m_sounds.erase(sound);
				}
				if (shouldDelete)
					bf = m_buffers.erase(bf);
				else
					++bf;
			}
		}
	}
}
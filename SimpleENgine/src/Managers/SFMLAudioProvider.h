#pragma once

#include "CacheSystem.h"
#include "AudioProviderInterface.h"

namespace sen {
    class SFMLAudioProvider : public AudioProviderInterface 
    {
    private:
        CacheSystem& m_cache;
        std::shared_ptr<sf::Music> m_currentMusic;
        std::shared_ptr<sf::Sound> m_currentSound;
    public:
        SFMLAudioProvider(CacheSystem& cache);
		virtual void playSound(const std::string& pathFile) override;
		virtual void playMusic(const std::string& pathFile) override;
		virtual void setVolume(int vol)						override;
		virtual ~SFMLAudioProvider() = default;
    };
}
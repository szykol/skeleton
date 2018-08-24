#pragma once

#include "SFMLCacheSystem.h"
#include "AudioProviderInterface.h"
#include "SFMLAudioProvider.h"
#include <memory>

namespace sen {
    class ResourceManager
    {
    private:
        static SFMLCacheSystem m_cache;
        // AudioProviderInterface* m_audioProvider;
        static SFMLAudioProvider m_audioProvider;
    public:
        static const sf::Font& getFont(const std::string& pathFile);
        static const sf::Texture& getTexture(const std::string& pathFile);
        static AudioProviderInterface& getAudioProvider() { return m_audioProvider; }
    };
}
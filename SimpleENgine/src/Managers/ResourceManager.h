#pragma once

#include "CacheSystem.h"
#include "AudioProviderInterface.h"
#include "SFMLAudioProvider.h"
#include <memory>

namespace sen {
    class ResourceManager
    {
    private:
        CacheSystem m_cache;
        // AudioProviderInterface* m_audioProvider;
        SFMLAudioProvider m_audioProvider;
    public:
        ResourceManager();
        const sf::Font& getFont(const std::string& pathFile);
        const sf::Texture& getTexture(const std::string& pathFile);
        AudioProviderInterface& getAudioProvider() { return m_audioProvider; }
    };
}
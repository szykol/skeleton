#include "Managers/CacheSystem.h"

namespace sen {
    CacheMap<sf::Font> CacheSystem::m_fonts;
    CacheMap<sf::Texture> CacheSystem::m_textures;
    CacheMap<sf::Music> CacheSystem::m_music;
    CacheMap<sf::SoundBuffer> CacheSystem::m_soundBuffers;
    float CacheSystem::s_time = 0.f;
    float CacheSystem::s_updateTime = 10.f;
    std::string CacheSystem::s_resourcesDir = RESOURCES_DIR;
#ifdef CUSTOM_RESOURCES_DIR
    std::string CacheSystem::s_customResourcesDir = CUSTOM_RESOURCES_DIR;
#endif

    void CacheSystem::update(float deltaTime) {
        s_time += deltaTime;

        if (s_time > s_updateTime) {
            updateMap(m_fonts);
            updateMap(m_textures);
            updateMap(m_music);
            updateMap(m_soundBuffers);

            s_time -= s_updateTime;
        }
    }
} // namespace sen

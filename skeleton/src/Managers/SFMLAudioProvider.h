#pragma once

#include "SFMLCacheSystem.h"
#include "AudioProviderInterface.h"

namespace sen {
    /** 
     * @brief  Basic audio provided that works
     * with sfml audio classes
     * @note   It's currently used in ResourceManager
     */
    class SFMLAudioProvider : public AudioProviderInterface 
    {
    private:
        SFMLCacheSystem& m_cache;
        std::shared_ptr<sf::Music> m_currentMusic;
        std::shared_ptr<sf::Sound> m_currentSound;
    public:
        /** 
         * @brief  Basic constructor
         * @note   
         * @param  cache: SFMLCacheSystem used to load 
         * audio from files
         */
        SFMLAudioProvider(SFMLCacheSystem& cache);
        /** 
         * @brief  Plays a sound
         * @param  pathFile: path to file
         */
		virtual void playSound(const std::string& pathFile) override;
        /** 
         * @brief  Plays (looped) music
         * @param  pathFile: path to file
         */
		virtual void playMusic(const std::string& pathFile, bool looping = false) override;
        /** 
         * @brief  Sets the volume of music
         * @param  vol: new volume
         * @retval None
         */
		virtual void setVolume(int vol)						override;
		virtual ~SFMLAudioProvider() = default;
    };
}
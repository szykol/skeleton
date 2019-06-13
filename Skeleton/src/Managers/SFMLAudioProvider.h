#pragma once

#include "AudioProviderInterface.h"

#include <deque>
#include <memory>

#include <SFML/Audio.hpp>

namespace sen {
    /** 
     * @brief  Basic audio provided that works
     * with sfml audio classes
     * @note   It's currently used in ResourceManager
     */
    class SFMLAudioProvider : public AudioProviderInterface 
    {
    private:
        std::shared_ptr<sf::Music> m_currentMusic;
		std::deque<sf::Sound> m_sounds;
		std::deque<std::shared_ptr<sf::SoundBuffer>> m_buffers;
		float m_updateTime = 5.f;
		float m_time = 0.f;
    public:
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
		/**
		 * @brief  Updates the implementation of soundprovider
         * checks if there are any weak_ptrs that are empty
         * to delete memory they are holding
		 */
		virtual void update(float deltaTime)				override;
		virtual ~SFMLAudioProvider() = default;
    };
}
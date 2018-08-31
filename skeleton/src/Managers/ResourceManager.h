#pragma once

#include "SFMLCacheSystem.h"
#include "AudioProviderInterface.h"
#include "SFMLAudioProvider.h"
#include <memory>

#include "../Config.h"

namespace sen {
    /** 
     * @brief  Basic ResourceManager that
     * manages fonts and textures (loads them from files
     * and keeps them in memory).
     * It also keeps an instance of AudioProvider
     * (default is SFMLAudioProvider, in future it will let
     * you change it to other Provider that implements
     * AudioProviderInterface) that lets you play
     * sounds and music
     */
    class ResourceManager
    {
    private:
        static SFMLCacheSystem m_cache;
        // AudioProviderInterface* m_audioProvider;
#ifdef DEFAULT_AUDIO_PROVIDER 
        static SFMLAudioProvider m_audioProvider;
#else
		static AudioProviderInterface* m_audioProvider;
#endif
    public:
        /** 
         * @brief  Returns font that is kept in memory
         * or loads a new one (if it wasn't used before)
         * from file.
         * @note   If font cannot be loaded, function will
         * return a default font
         * @param  pathFile: path to Font
         */
        static const sf::Font& getFont(const std::string& pathFile);
        /** 
         * @brief  Returns a texture that is kept in memory
         * or loads a new one (if it wasn't used before)
         * from file.
         * @note   If texture cannot be loaded, function will
         * return a default texture
         * @param  pathFile: path to texture
         * @retval 
         */
        static const sf::Texture& getTexture(const std::string& pathFile);
#ifdef DEFAULT_AUDIO_PROVIDER
		/**
		* @brief  Returns current AudioProvider (default is SFMLAudioProvider)
		* @note   AudioProvider can be used for playing sounds and music
		*/
        static AudioProviderInterface* getAudioProvider() { return &m_audioProvider; }
#else
		/**
		* @brief  Returns current AudioProvider (default is nullptr)
		* @note   AudioProvider can be used for playing sounds and music
		*/
		static AudioProviderInterface* getAudioProvider() { return m_audioProvider; }
		/**
		* @brief  Lets you register other audio provider class that implements
		* AudioProvider interface
		*/
		static void registerAudioProvider(AudioProviderInterface* audioProvider) { m_audioProvider = audioProvider; }
#endif // !DEFAULT_AUDIO_PROVIDER

    };
}
#pragma once

#include "AudioProviderInterface.h"
#include "SFMLAudioProvider.h"
#include <memory>

namespace sen {
    /** 
     * @brief keeps an instance of AudioProvider
     * (default is SFMLAudioProvider, lets
     * you change it to other Provider that implements
     * AudioProviderInterface) that lets you play
     * sounds and music
     */
    class AudioProvider
    {
    private:
        static std::unique_ptr<AudioProviderInterface> m_audioProvider;
    public:
		/**
		* @brief  Returns current AudioProvider (default is nullptr)
		* @note   AudioProvider can be used for playing sounds and music
		*/
		static AudioProviderInterface* get() { return m_audioProvider.get(); }
		/**
		* @brief  Lets you register other audio provider class that implements
		* AudioProvider interface
		*/
		static void registerProvider(std::unique_ptr<AudioProviderInterface> audioProvider) { m_audioProvider = std::move(audioProvider); }
    };
}
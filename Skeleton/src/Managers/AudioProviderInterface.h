#pragma once

#include <string>

namespace sen {
	/** 
	 * @brief  Basic AudioProviderInterface
	 * that can be used with ResourceManager
	 */
	class AudioProviderInterface
	{
	public:
		/** 
		 * @brief  Plays a sound
		 * @param  pathFile: path to file
		 */
		virtual void playSound(const std::string& pathFile) = 0;
		/** 
		 * @brief  PLays music. Can be looped
		 * @param  pathFile: path to file
		 * @param  looping: if true the music will be looped
		 * @retval None
		 */
		virtual void playMusic(const std::string& pathFile, bool looping = false) = 0;
		/** 
		 * @brief  Sets music volume
		 * @param  vol: music volume
		 */
		virtual void setVolume(int vol) = 0;
		/**
		 * @brief  Updates (if needed)
		 * and deletes not used memory
		 * @param  vol: music volume
		 */
		virtual void update(float deltaTime) {}

		virtual ~AudioProviderInterface() = default;
	};
}
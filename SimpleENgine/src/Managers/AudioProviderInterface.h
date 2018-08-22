#pragma once

#include <string>

namespace sen {
	class AudioProviderInterface
	{
	public:
		virtual void playSound(const std::string& pathFile) = 0;
		virtual void playMusic(const std::string& pathFile) = 0;
		virtual void setVolume(int vol) = 0;
	};
}
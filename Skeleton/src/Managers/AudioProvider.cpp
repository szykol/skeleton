#include "AudioProvider.h"


namespace sen {
	std::unique_ptr<AudioProviderInterface> AudioProvider::m_audioProvider = nullptr;
}
#include "SFMLCacheSystem.h"

#include <iostream>

namespace sen {
	void SFMLCacheSystem::update()
	{
		// only soundBuffers and music are removed if not being used
		// textures and fonts are stored in the memory and not being
		// deleted
		
		if (!m_soundBuffers.empty())
		{
			for (auto it = m_soundBuffers.begin(); it != m_soundBuffers.end(); it++)
			{
				if (it->second.shouldRemove())
				{
					m_soundBuffers.erase(it);
					break;
				}
			}
		}
		if (!m_music.empty())
		{
			for (auto it = m_music.begin(); it != m_music.end(); it++)
			{
				if (it->second.shouldRemove())
				{
					m_music.erase(it);
					break;
				}
			}
		}
	}
}
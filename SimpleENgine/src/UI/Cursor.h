#pragma once

#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Box.h"

namespace sen {
	class Cursor : public Box, sf::NonCopyable
	{
	private:
		sf::Clock m_timer;
		unsigned char m_alpha;
		const Text& m_text;
		float m_delay;
	public:
		Cursor(const Text& text);
		void render(sf::RenderTarget& target);
		void setCursor();
	};
}
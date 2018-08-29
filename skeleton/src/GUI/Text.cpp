#include "Text.h"
#include "Box.h"

namespace sen {
	Text::Text(const sf::String & string, unsigned int fontSize, const sf::Font & font)
		: sf::Text(string, font, fontSize), m_boundsChanged(false), m_boundsStatusReset(false)
	{
		setOriginMode(OriginMode::CENTER);
		originSet();
	}

	void Text::render(sf::RenderTarget & target)
	{

		// this resets the "changed bounds" status
		// one frame after actually changing bounds
		// and lets you catch that the text has changed
		// and perform an action
		if (m_boundsStatusReset)
			m_boundsChanged = false;
		// if status has been changed enable resetting
		// in the next frame
		if (m_boundsChanged)
			m_boundsStatusReset = true;
		else
			m_boundsStatusReset = false;

		target.draw(*this);
	}

	void Text::setCharacterSize(unsigned int size)
	{
		m_boundsChanged = true;
		sf::Text::setCharacterSize(size);

		// when size of text changes and text is in center mode we need to update the origin
		// so the text will be set in the middle (the bounds have changed)
		originSet();
	}

	void Text::setOriginMode(OriginMode mode)
	{
		if (m_originMode == mode)
			return;

		m_originMode = mode;
		
		originSet();
	}

	void Text::setString(const sf::String & string)
	{
		m_boundsChanged = true;
		sf::Text::setString(string);
		originSet();
	}

	bool Text::haveBoundsChanged() const
	{
		return m_boundsChanged;
	}

	Text::~Text()
	{
	}
	
	void Text::originSet()
	{
		if (m_originMode == OriginMode::CENTER)
		{
			sf::FloatRect bounds = getLocalBounds();
			setOrigin(sf::Vector2f(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f));
		}
		else
		{
			setOrigin(0.f, 0.f);
		}
	}
}
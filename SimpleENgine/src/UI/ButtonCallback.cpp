#include "ButtonCallback.h"

namespace sen {
	ButtonCallback::ButtonCallback(const sf::String & string)
		:Button(string)
	{
	}
	void ButtonCallback::onHover()
	{
		if (m_onHoverCallback)
			m_onHoverCallback(*this);
		else
			Button::onHover();
	}
	void ButtonCallback::onUnhover()
	{
		if (m_onUnhoverCallback)
			m_onUnhoverCallback(*this);
		else
			Button::onUnhover();
	}
	void ButtonCallback::onClick()
	{
		if (m_onClickCallback)
			m_onClickCallback(*this);
		else
			Button::onClick();
	}
}

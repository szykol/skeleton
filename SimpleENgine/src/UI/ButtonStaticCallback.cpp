#include "ButtonStaticCallback.h"

namespace sen {
	std::function<void(ButtonStaticCallback &)>
		ButtonStaticCallback::s_onHoverCallback;
	std::function<void(ButtonStaticCallback &)>
		ButtonStaticCallback::s_onUnhoverCallback;
	std::function<void(ButtonStaticCallback &)>
		ButtonStaticCallback::s_onClickCallback;

	ButtonStaticCallback::ButtonStaticCallback(const sf::String & string)
		: Button(string) {}

	void ButtonStaticCallback::onHover()
	{
		if (s_onHoverCallback)
			s_onHoverCallback(*this);
		else
			Button::onHover();
	}
	void ButtonStaticCallback::onUnhover()
	{
		if (s_onUnhoverCallback)
			s_onUnhoverCallback(*this);
		else
			Button::onUnhover();
	}
	void ButtonStaticCallback::onClick()
	{
		if (s_onClickCallback)
			s_onClickCallback(*this);
		else
			Button::onClick();
	}
	
}
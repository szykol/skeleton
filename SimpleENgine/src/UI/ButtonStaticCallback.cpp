#include "ButtonStaticCallback.h"

namespace sen {
	std::function<void(ButtonStaticCallback &)>
		ButtonStaticCallback::onHoverCallback;
	std::function<void(ButtonStaticCallback &)>
		ButtonStaticCallback::onUnhoverCallback;
	std::function<void(ButtonStaticCallback &)>
		ButtonStaticCallback::onClickCallback;

	ButtonStaticCallback::ButtonStaticCallback(const sf::String & string)
		: Button(string) {}

	void ButtonStaticCallback::onHover()
	{
		if (this->onHoverCallback)
			this->onHoverCallback(*this);
		else
			Button::onHover();
	}
	void ButtonStaticCallback::onUnhover()
	{
		if (this->onUnhoverCallback)
			this->onUnhoverCallback(*this);
		else
			Button::onUnhover();
	}
	void ButtonStaticCallback::onClick()
	{
		if (this->onClickCallback)
			this->onClickCallback(*this);
		else
			Button::onClick();
	}
	
}
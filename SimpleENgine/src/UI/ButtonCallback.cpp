#include "ButtonCallback.h"

namespace sen {
	ButtonCallback::ButtonCallback(const sf::String & string)
		:Button(string)
	{
	}
	void ButtonCallback::onHover()
	{
		if (this->onHoverCallback)
			this->onHoverCallback(*this);
		else
			Button::onHover();
	}
	void ButtonCallback::onUnhover()
	{
		if (this->onUnhoverCallback)
			this->onUnhoverCallback(*this);
		else
			Button::onUnhover();
	}
	void ButtonCallback::onClick()
	{
		if (this->onClickCallback)
			this->onClickCallback(*this);
		else
			Button::onClick();
	}
}

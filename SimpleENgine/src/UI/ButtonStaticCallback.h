#pragma once

#include "InterfaceButton.h"
#include <functional>

namespace sen {
	class ButtonStaticCallback : public Button
	{
	public:
		static std::function<void(ButtonStaticCallback &)> onHoverCallback;
		static std::function<void(ButtonStaticCallback &)> onUnhoverCallback;
		static std::function<void(ButtonStaticCallback &)> onClickCallback;
		ButtonStaticCallback(const std::string &string);

		virtual void onHover()	 override;
		/**
		Overriden from InterfaceButton.
		Calls the onUnhoverCallback.

		*/
		virtual void onUnhover() override;
		/**
		Overriden from InterfaceButton.
		Calls the onClickCallback.
		*/
		virtual void onClick()	 override;
	};
}
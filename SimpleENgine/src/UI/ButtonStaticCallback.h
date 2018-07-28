#pragma once

#include "Button.h"
#include <functional>

namespace sen {
	/**
		Button that uses static callbacks rather than overriding virtual functions from
		Button. If you plan to use the same callbacks for your
		buttons use this class. Otherwise see the TextButtonCallback
		which uses non-static callbacks.
	*/
	class ButtonStaticCallback : public Button
	{
	public:
		static std::function<void(ButtonStaticCallback &)> s_onHoverCallback;
		static std::function<void(ButtonStaticCallback &)> s_onUnhoverCallback;
		static std::function<void(ButtonStaticCallback &)> s_onClickCallback;
		
		/**
			Basic constructor that calls Button constructor

			@param string Text that will be displayed on the button
		*/
		explicit ButtonStaticCallback(const sf::String &string);
		/**
			Overriden from Button.
			Calls the onHoverCallback.
		*/
		virtual void onHover()	 override;
		/**
			Overriden from Button.
			Calls the onUnhoverCallback.
		*/
		virtual void onUnhover() override;
		/**
			Overriden from Button.
			Calls the onClickCallback.
		*/
		virtual void onClick()	 override;
		virtual ~ButtonStaticCallback() = default;
	};
}
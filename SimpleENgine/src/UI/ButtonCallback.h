#pragma once

#include "Textbox.h"
#include <functional>
#include "Button.h"

namespace sen {
	/**
		Button that uses callbacks rather than overriding virtual functions from 
		InterfaceButton. If you plan to use different callbacks for your 
		buttons use this class. Otherwise see the TextButtonStaticCallback
		which uses static callbacks, or create your own class using 
		TextButton class as a base.
	*/
	class ButtonCallback : public Button
	{
	public:
		std::function<void(ButtonCallback &)> onHoverCallback;
		std::function<void(ButtonCallback &)> onUnhoverCallback;
		std::function<void(ButtonCallback &)> onClickCallback;
		/**
			Basic constructor that calls InterfaceButton constructor

			@param string Text that will be displayed on the button
		*/
		ButtonCallback(const std::string &string);
		/**
			Overriden from InterfaceButton.
			Calls the onHoverCallback.
		*/
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

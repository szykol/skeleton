#pragma once

#include "Textbox.h"
#include <functional>
#include "Button.h"

namespace sen {
	/**
	 *	Button that uses callbacks rather than overriding virtual functions from 
	 *	Button. If you plan to use different callbacks for your 
	 *	buttons use this class. Otherwise see the TextButtonStaticCallback
	 *	which uses static callbacks, or create your own class using 
	 *	TextButton class as a base.
	 */
	class ButtonCallback : public Button
	{
	public:
		std::function<void(ButtonCallback &)> m_onHoverCallback;
		std::function<void(ButtonCallback &)> m_onUnhoverCallback;
		std::function<void(ButtonCallback &)> m_onClickCallback;
		/**
		 *	Basic constructor that calls Button constructor
		 *
		 *	@param string Text that will be displayed on the button
		 */
		explicit ButtonCallback(const sf::String &string);
		/**
		 *	Overriden from Button.
		 *	Calls the onHoverCallback.
		 */
		virtual void onHover()	 override;
		/**
		 *	Overriden from Button.
		 *	Calls the onUnhoverCallback.
		 */
		virtual void onUnhover() override;
		/**
		 *	Overriden from Button.
		 *	Calls the onClickCallback.
		 */
		virtual void onClick()	 override;
		virtual ~ButtonCallback() = default;
	};
}

#pragma once

#include "Button.h"
#include "../Util/InputController.h"

namespace sen {
	class InputBox : public Button
	{
	private:
		InputController m_ic;
		sf::String m_placeholder;
		bool m_hasFocus;
	public:
		InputBox(const sf::String& placeholder);
		/**
			This should be whole logic of the button, checks if mouse hovers over the button, if button is clicked etc

			@param window Window needed to get the position of Mouse
		*/
		virtual void update(sf::RenderWindow &window) override;
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
		void onFocus();
		void render(sf::RenderTarget &target);
	};
}
#pragma once

#include "Textbox.h"
#include "InterfaceButton.h"

namespace sen {
	class TextButton : public TextBox, public InterfaceButton
	{
	public:
		TextButton(const std::string &string);
		void render(sf::RenderTarget &target);
		virtual void onHover()		override;
		virtual void onUnhover()	override;
		virtual void onClick()		override;
		virtual void onUnClick()	override;
	};
}
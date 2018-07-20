#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

typedef std::function<void(void)> Callback;

namespace sen {
	class InterfaceButton
	{
		sf::Clock timer;
		bool clickable = true;
		Callback onClickFunc;
	protected:
		virtual void onHover() = 0;
		virtual void onUnhover() = 0;
		virtual void onClick() = 0;
		virtual void onUnClick() = 0;
		void setOnClickFunction(const Callback &func) { onClickFunc = func; }
	};
}
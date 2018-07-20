#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

typedef std::function<void(void)> Callback;

namespace sen {
	class InterfaceButton
	{
	protected:
		sf::Clock timer;
		bool clickable = true;
		Callback onClickFunc;
	public:
		virtual void update(const sf::RenderWindow &window) = 0;
	protected:
		virtual void onHover() = 0;
		virtual void onUnhover() = 0;
		virtual void onClick() = 0;
		virtual void onUnClick() = 0;
		virtual bool mouseOver(const sf::RenderWindow &window) = 0;
	public:
		void setOnClickFunction(const Callback &func) { onClickFunc = func; }
	};
}
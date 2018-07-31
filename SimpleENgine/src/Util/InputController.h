#pragma once

#include "../UI/Cursor.h"
#include "../UI/Text.h"
#include <functional>

typedef std::function<bool(const sf::String& string)> stringValidateFunc;

namespace sen {
	class InputController
	{
	private:
		Text & m_text;
		Cursor m_cursor;
		stringValidateFunc m_validateFunc;
	public:
		InputController(Text& text);
		void handleInput(const sf::Event& evnt);
		//void update();
		void render(sf::RenderTarget& target);
		bool validate();
		void setValidateFunction(const stringValidateFunc& func) { m_validateFunc = func; }
	};
}
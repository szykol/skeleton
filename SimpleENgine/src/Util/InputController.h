#pragma once

#include "../UI/Cursor.h"
#include "../UI/Text.h"
#include <functional>

typedef std::function<bool(const sf::String& string)> stringValidateFunc;

namespace sen {
	class InputController : sf::NonCopyable
	{
	private:
		static Text* s_text;
		static Cursor s_cursor;
		static stringValidateFunc s_validateFunc;
		static bool s_isBound;
		InputController() = default;
		~InputController() = default;
	public:
	    static void bindText(Text& text);
		static void unbindText();
		static inline bool isBound() {return s_isBound;}
		static void handleInput(const sf::Event& evnt);
		//void update();
		static void render(sf::RenderTarget& target);
		static bool validate();
		static void setValidateFunction(const stringValidateFunc& func) { s_validateFunc = func; }
	};
}
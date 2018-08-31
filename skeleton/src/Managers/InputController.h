#pragma once

#include "../GUI/Cursor.h"
#include "../GUI/Text.h"
#include <functional>

namespace sen {
	using stringValidateFunc = std::function<bool(const sf::String& string)>;
	/** 
	 * @brief  Controlls the user input and changes
	 * Text object based on input. 
	 * If you need to enable changing the string 
	 * of a text object you need to bind it
	 * to the input controller.
	 * Will be able to validate the input, by using the 
	 * validation function which you can specify yourself
	 */
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
		/** 
		 * @brief  Lets you bind the text object
		 * @note   It will unbind the previous 
		 * text object
		 * @param  text: Text you want to bind to
		 * @retval None
		 */
	    static void bindText(Text& text);
		/** 
		 * @brief  Unbinds the current text object
		 * @retval None
		 */
		static void unbindText();
		/** 
		 * @brief  Returns true if is bound
		 * to a text object
		 */
		static inline bool isBound() {return s_isBound;}
		/** 
		 * @brief  Handles all key entered events
		 * @param  evnt: event from sf::RenderWindow::pollEvents
		 * @retval None
		 */
		static void handleInput(sf::Event& evnt);
		/** 
		 * @brief  Renders the cursor
		 * @param  target: Target you want to render to 
		 * @retval None
		 */
		static void render(sf::RenderTarget& target);
		/** 
		 * @brief  Updates the cursor
		 * @param  deltaTime: time since last frame
		 * @retval None
		 */
		static void update(float deltaTime);
		/** 
		 * @brief  validates the input, returns
		 * true if input is correct.
		 */
		static bool validate();
		/** 
		 * @brief  Sets the validation function
		 * which validates the user input
		 * @param  func: new validation function
		 * @retval None
		 */
		static void setValidateFunction(const stringValidateFunc& func) { s_validateFunc = func; }
	};
}
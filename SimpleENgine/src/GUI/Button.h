#pragma once

#include "Textbox.h"
#include "ButtonController.h"

#include <functional>
#include <unordered_map>

namespace sen {
    enum class ButtonEvent {STANDARD, HOVER, CLICK};
    class Button;

    using OnClickCallback = std::function<void(void)>;
    using Callback = std::function<void(Button&)>;
    using ButtonAction = std::pair<Callback, bool>;
    using CallbackMap = std::unordered_map<ButtonEvent, ButtonAction>;

    class Button : public TextBox
    {
	friend class ButtonController;
    protected:
		sf::Clock m_timer;
		bool clickable = false;
        OnClickCallback m_clickCallback;
        CallbackMap* m_callbacks;
		sf::String m_standardString;
	public:
		explicit Button(const sf::String &string)
			: TextBox(string), m_standardString(string),
			  m_callbacks(nullptr) {}
		/**
		 *	This should change the button on mouse hover
		 */
		virtual void onHover();
		/**
		 *	This should change the button on mouse leaving the button
		 */
		virtual void onUnhover();
		/**
		 *	This should change the button on mouse click
		 */
		virtual void onClick();
		/**
		 *	This should be whole logic of the button, checks if mouse hovers over the button,
		 *  if button is clicked etc
		 *
		 *	@param window Window needed to get the position of Mouse
		 */
		virtual void update(sf::RenderWindow &window);
		/**
		 *	Checks if a Mouse hovers over the button
		 */
		virtual bool mouseOver(const sf::RenderWindow &window);
		/**
		 *	Sets a callback function called on mouse click
		 */
		void setOnClickCalback(const OnClickCallback &callback) { m_clickCallback = callback; }
		/** 
		 * @brief  sets a callback function and calls it when an event occurs
		 * @note   if you change the button when the "hover" or "click"
		 * event occurs, you need to explicitly specify all standard 
		 * looks of the button in the "standard" event for example:
		 * if you change the size of a button, you need to set its 
		 * basic size in "standard" callback
		 * --- You do not need to specify the standard text which 
		 * is passed in the constructor ---.
		 * 
		 * @param  event: either one of HOVER, CLICK, STANDARD
		 * @param  callback: function to perform an action on button
		 * it takes a button reference as a parameter
		 * @param  preventDefault: prevent default behaviour of 
		 * the button
		 * @retval None
		 */
        void addListener(ButtonEvent state, const Callback& callback, bool preventDefault = false);
		virtual ~Button();
    private:
        const ButtonAction* getCallbackForState(ButtonEvent state) const;
    };
}
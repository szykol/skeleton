#pragma once

#include "TextBox.h"
#include "../Managers/ButtonController.h"

#include <functional>
#include <unordered_map>

namespace sen {
    enum class ButtonEvent {STANDARD, HOVER, CLICK};
    class Button;

    using OnClickCallback = std::function<void(void)>;
    using Callback = std::function<void(Button&)>;
    using ButtonAction = std::pair<Callback, bool>;
    using CallbackMap = std::unordered_map<ButtonEvent, ButtonAction>;

	/** 
	 * @brief  extends TextBox class and 
	 * provides a simple button functionality
	 * (changes on hover etc). Let's the user
	 * specify how the button should behave on
	 * certain events (see Button::addListener)
	 */
    class Button : public TextBox
    {
	friend class ButtonController;
    protected:
		float m_time = 0.f;
		bool clickable = false;
		bool m_active = true;
        OnClickCallback m_clickCallback;
        std::unique_ptr<CallbackMap> m_callbacks;
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
		virtual void update(float deltaTime);
		/**
		 *	Checks if a Mouse hovers over the button
		 */
		virtual bool mouseOver();
		/**
		 *	Sets a callback function called on mouse click
		 */
		void setOnClickCallback(const OnClickCallback &callback) { m_clickCallback = callback; }
		/** 
		 * @brief  Used for changing the look of a button.
		 * Sets a callback function and calls it when an event occurs
		 * @note   if you change the button when the "hover" or "click"
		 * event occurs, you need to explicitly specify all standard 
		 * looks of the button in the "standard" event for example:
		 * if you change the size of a button, you need to set its 
		 * basic size in "standard" callback
		 * 
		 * @param  event: either one of HOVER, CLICK, STANDARD
		 * @param  callback: function to perform an action on button
		 * it takes a button reference as a parameter
		 * @param  preventDefault: prevent default behaviour of 
		 * the button
		 * @retval None
		 */
        void addListener(ButtonEvent state, const Callback& callback, bool preventDefault = false);
		/**
		 * @brief  Check if the button is active
		 */
		bool isActive() const { return m_active; }
		/**
		 * @brief  Set active state of a button
		 */
		void setActive(bool active) { m_active = active; }

		Button(const Button&) = default;
		Button& operator=(const Button&) = default;
		Button(Button&&) = default;
		Button& operator=(Button&&) = default;
    private:
		/** 
		 * @brief  Returns callbacks changing the looks of button
		 * specified by user
		 * @note   It's used for implementation of button but doesn't
		 * need to be used outside of the class
		 * @param  state: either HOVER/CLICK/STANDARD
		 * @retval ButtonAction action to perform on button
		 */
        const ButtonAction* getCallbackForState(ButtonEvent state) const;
    };
}
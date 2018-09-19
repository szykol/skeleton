#pragma once

#include "Button.h"

namespace sen {
	/** 
	 * @brief  Enables user input. Can validate that input.
	 * @note   This class isn't fully supported by the
	 * ButtonController class yet. 
	 */
	class InputBox : public Button
	{
	private:
		sf::String m_placeholder;
		bool m_hasFocus;
	public:
		explicit InputBox(const sf::String& placeholder = "placeholder...");
		/** 
		 * @brief  Checks if user pressed the box. If it has
		 * gained focus, the input will be enabled. Otherwise
		 * it will show the current value of the text inside the box.
		 * @note   Use this method ONLY if you're not using this class
		 * with ButtonController (as it updates the buttons itself)
		 * @param  &window: Window needed to get position of mouse
		 * @retval None
		 */
		//virtual void update(sf::RenderWindow &window) override;
		/** 
		 * @brief  Performs an action when mouse hovers over box
		 * @note   This method is overriden from Button class.
		 * @retval None
		 */
		virtual void onHover()	 override;
		/** 
		 * @brief  Performs an action when mouse leaves box
		 * @note   This method is overriden from Button class.
		 * @retval None
		 */
		virtual void onUnhover() override;
		/** 
		 * @brief  Performs an action when mouse is clicked over box
		 * @note   This method is overriden from Button class.
		 * @retval None
		 */
		virtual void onClick()	 override;
		/** 
		 * @brief  Performs an action when box gains focus
		 * @retval None
		 */
		void onFocus();
		/** 
		 * @brief  Returns the string that is displayed in box
		 * @retval sf::String& current text value of box
		 */
		const sf::String& getString() const;
		/** 
		 * @brief  Renders the box
		 * @param  &target: Target you want to draw on
		 * @retval None
		 */
		void render(sf::RenderTarget &target);
		/** 
		 * @brief  Returns true if the input has focus
		 */
		bool hasFocus() const {return m_hasFocus;}
		/**
		 * @brief Returns the placeholder of inputbox
		 */
		const sf::String& getPlaceholder() const { return m_placeholder; }
		virtual ~InputBox();

		InputBox(const InputBox&) = default;
		InputBox& operator=(const InputBox&) = default;
		InputBox(InputBox&&) = default;
		InputBox& operator=(InputBox&&) = default;
	};
}
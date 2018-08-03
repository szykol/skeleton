#pragma once

#include <SFML/Graphics.hpp>

#include "TextBox.h"
#include "../vendor/nlohmann/json.hpp"
#include <functional>


typedef std::function<void(void)> onClickCallback;
using json = nlohmann::json;

namespace sen {
	/**
	 *	Provides an interface for button functionality.
	 *	Those virtual voids need to be overriden in order to specify how button behaves. 
	 *	Provides callback function that's being called whenever user presses the button
	 */
	class jButton : public TextBox
	{
	protected:
        static json s_globalSettings;
        json* m_jsonSettings; // use it only if user
        //has specified other settings for the button
		sf::Clock m_timer;
		bool clickable = false;
	public:
		onClickCallback m_callback;
		explicit jButton(const sf::String &string) : TextBox(string) {}
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
		void setOnClickCalback(const onClickCallback &callback) { m_callback = callback; }
        static void printGlobalSettings();
		virtual ~jButton() = default;
	};
}
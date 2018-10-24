#pragma once
#include <SFML/Graphics.hpp>
#include "../Application.h"
#include "Transformable.h"
namespace sen {
	/**
	 *	Lets you choose where to set the origin
	 */
	enum class OriginMode {CENTER, TOPLEFT};
	/**
	 *	Just a basic wrapper for sf::Text class.
	 *	Lets you easily change origin of the text using OriginMode enum.
	 */
	class Text : public sf::Text, public Transformable
	{
	private:
		OriginMode m_originMode;
		bool m_boundsChanged = false;
		bool m_boundsStatusReset = false;
		bool m_updateOnlyXAxis = false;
	public:
		/**
		 *	Lets you specify the string, fontsize and font that will be used in this object.
         *
		 *	@param string String that will be displayed.
		 *	@param fontSize Font size. Default value = 30U.
		 *	@param font Font used to display the text. Default font is Roboto.
		 */
		explicit Text(const sf::String &string, unsigned int fontSize = 30U, 
			 const sf::Font &font = Application::getDefaultFont());
		/**
		 *	Draws the box on the target
		 *
		 *	@param target Target you want to draw text on
		 */
		void render(sf::RenderTarget &target);
		/**
		 *	Sets character size of text and resets the origin.
         *
		 *	@param size Size of text
		 */
		void setCharacterSize(unsigned int size);
		/**
		 *	Sets origin mode.
		 *	OriginMode::CENTER sets origin to the middle of the object's bounds.
		 *	OriginMode::TOPLEFT sets origin to the top left which is default
		 *	in SFML library. You can still set origin to whatever you need using
		 *	setOrigin function.
         * 
		 *	@param mode Where to set origin
		 */
		void setOriginMode(OriginMode mode);
		/**
		 *	Returns the origin mode.
		 *	OriginMode::CENTER sets origin to the middle of the object's bounds.
		 *	OriginMode::TOPLEFT sets origin to the top left which is default
		 *	in SFML library.
         *
		 *	@return The origin mode
		 */
		OriginMode getOriginMode() const { return m_originMode; }
		/**
		 *	sets the new string.
         *
		 *	@param string New string.
		 */
		void setString(const sf::String &string);
		/** 
		 * @brief  This method will return true
		 * if size of text has changed
		 * @note   It's used for the implementation
		 * of textBox and inputText which are able
		 * to change size of text if user specified
		 * that behaviour
		 * @retval 
		 */
		bool haveBoundsChanged() const;
		/**
		 * @brief  When text changes size this makes sure
		 * it won't move on the Y axis but text will still be
		 * centered on X axis
		 * @note   This means the text won't be centered around it's
		 * position anymore
		 */
		void setUpdateOnlyXAxis(bool update) {m_updateOnlyXAxis = update;}


		/* all of those methods are overriden to enable animating the movement
			of this object */
		virtual void setPosition(float x, float y, float speed)			override;
		virtual void setPosition(float x, float y)						override;
		virtual void setPosition(const sf::Vector2f& pos)				override;
		virtual void setPosition(const sf::Vector2f& pos, float speed)  override;
		virtual const sf::Vector2f& getPosition() const					override;
		virtual void move(float x, float y)								override;
		virtual void move(const sf::Vector2f& vect)						override;
		
		virtual ~Text() = default;
		Text(const Text&) = default;
		Text& operator=(const Text&) = default;
		Text(Text&&) = default;
		Text& operator=(Text&&) = default;

	private:
		// sets origin in the middle if origin mode is set
		void originSet();
	};
}

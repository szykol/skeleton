#pragma once

#include "Button.h"

#include <vector>
#include <memory>
#include <functional>

namespace sen {
	class Button;
	typedef std::shared_ptr<Button> ButtonPointer;
	typedef std::vector<ButtonPointer> ButtonPointerVector;
	enum class ButtonPlacing {HORIZONTAL, VERTICAL};
	enum class ButtonBaseline {START, CENTER, END};
	/**
	 * 	All the buttons you pass to the controller will be
	 *	updated and rendered. Additionaly controller has built 
	 *	in logic that lets the user navigate through all of these
	 *	buttons. It should be used in all sorts of menus.
	 *	It can place all buttons evenly on the screen aswell as 
	 *	set the same size for all of them.
	 *	You will be able to pass the function to execute on each one
	 *	of buttons.
	 */
	class ButtonController
	{
		bool m_nonStandardPosition = false;
		bool m_sameSize = true;
		float m_coord;
		ButtonPointerVector m_buttons;
		int m_activeIndex = 0;
		sf::Clock m_timer;
		bool m_canClick = false;
		ButtonPlacing m_buttonPlacing = ButtonPlacing::VERTICAL;
		ButtonBaseline m_baseline = ButtonBaseline::CENTER;
	public:
		/**
	     *	Default constructor of the controller.
		 */
		ButtonController() = default;
		/**
		 *	Constructor that takes the vector of button pointers
		 *	and makes a copy.
         *
		 *	@param buttons A vector of button pointers
		 */
		explicit ButtonController(const ButtonPointerVector &buttons);
		/**
		 *	Constructor that takes the vector of button pointers
		 *	and makes a copy. It places all buttons evenly on the
		 *	screen.
		 *	
		 *	@param buttons A vector of button pointers
		 *	@param window Window is needed for placing the buttons
		 */
		ButtonController(const ButtonPointerVector& buttons, const sf::RenderWindow &window);
		/** 
		 * @brief  Changes placing buttons to Horizontaly/Verticaly
		 * @note   Default setting is vertical
		 * @param  placing: Either VERTICAL/HORIZONTAL
		 * @retval None
		 */
		inline void setButtonPlacing(ButtonPlacing placing) {m_buttonPlacing = placing;}
		/** 
		 * @brief  Returns current ButtonPlacing (HORIZONTAL/VERTICAL)
		 * @retval 
		 */
		inline ButtonPlacing getButtonPlacing() const {return m_buttonPlacing;}
		/**
		 *	Adds the button pointer to the vector
         *
		 *	@param button Button pointer wich will be added to the vector
		 */
		void pushButtons(ButtonPointer& button);
		/**
		 *	Pass all buttons with single function call
		 */
		template<typename... Args>
		void pushButtons(ButtonPointer& button, Args... args)
		{
			m_buttons.push_back(button);

			pushButtons(args...);
		}
		/** 
		 * @brief  Adds a button at the end. The button is constructed
		 * by the std::vector<t>::emplace_back function
		 * @param  arguments: Arguments that will be forwarded
		 * to the constructor of button shared pointer.
		 * example: 
		 *  (new Button("something"))
		 * @retval None
		 */
		template<typename... Args>
		void emplaceButtons(Args&&... args)
		{
			m_buttons.emplace_back(args...);
		}
		/**
		 *	Removes last added button 
		 */
		void removeButton();
		/**
		 *	Contains all the logic needed to navigate through menu.
		 *
		 *	@param window Window needed to get the mouse position.
		 */
		void update(sf::RenderWindow &window);
		/**
		 *	Renders all buttons.
         *
		 *	@param target Target to render on.
		 */
		void render(sf::RenderTarget &target);
		/**
		 *	Places the buttons evenly on the screen.
         *
		 *	@param window Window needed to get it's size.
		 *	@param gap Gap between buttons
		 */
		void placeButtons(const sf::RenderWindow &window, float gap = 30.f);
		/** 
		 * @brief  Places buttons evenly on the screen within the bounds
		 * @note   If you want to place buttons on the window you can
		 * pass window instead of bounds
		 * @param  bounds: Bounds you want to place buttons within
		 * @param  gap: Gap between buttons
		 * @retval None
		 */
		void placeButtons(const sf::FloatRect& bounds, float gap = 30.f);
		/** 
		 * @brief  Set baseline of buttons (either START/CENTER/END).
		 * If ButtonPlacing is set to vertical those buttons will be
		 * placed according to y axis else they will be placed
		 * according to x axis.
		 * For example: setting Baseline to START while ButtonPlacing
		 * is set to vertical -> pushes all buttons to the left side
		 * of bounding box, but setting same baseline while ButtinPlacing
		 * is set to horizontal -> pushes all buttons to the top.
		 * @note   It acts similiar to css flexbox
		 * @param  baseline: 
		 * @retval None
		 */
		void setButtonBaseline(ButtonBaseline baseline) {m_baseline = baseline;}
		/** 
		 * @brief  Sets either x/y coordinate (based on ButtonPlacing mode)
		 * @note   Use it if you want place all buttons x/y coord to a specific
		 * value (x/y coord now will be set to new position)
		 * @param  coord: Coord new coordinate value
		 * @retval None
		 */
		void setCoord(float coord);
		/** 
		 * @brief  Move every button by the offset based on the 
		 * ButtonPlacing mode
		 * @note   If ButtonPlacing::Horizontal -> it will move
		 * buttons by the offset horizontaly and so on
		 * @param  offset: 
		 * @retval None
		 */
		void setOffset(float offset);
		/**
		 *	Sets the same size for all buttons.
         *
		 *	@param size New size
		 */
		void setButtonFixedSize(const sf::Vector2f &size);
		/** 
		 * @brief  Sets the same size for all buttons
		 * @note   It sets the size of the biggest button
		 * @param  set: Whether to set the same size 
		 * @retval None
		 */
		void setButtonSameSize(bool set) { m_sameSize = set; }
		/**
		 *	Performs an specified action on each button.
 		 *
		 *	@param function Function that does something with button and
		 *		   takes a button pointer as a parameter
		 */
		void map(const std::function<void(ButtonPointer&)> &function);
	private:
		/** 
		 * @brief  Returns biggest size of all
		 * buttons that it controlls
		 * @note   It's used for implementation only
		 * @retval sf::Vector2f size of biggest button
		 */
		sf::Vector2f getBiggestSizeOfButton();
		/** 
		 * @brief  If user specified that buttons
		 * should all have the same size it sets it
		 * @note   It's used for implementation only
		 * @param  biggestSize: 
		 * @retval None
		 */
		void  checkIfSameSize(float biggestSize);
	};
}
#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

/** 
 * @brief  Takes care of updating and rendering the engine.
 * It also holds the reference to window so it's easier 
 * to acess it from every place in the program.
 * Remembers initial window size needed to place
 * entities correctly (placing them based on initial size, rather than
 * current window size. This only applies when window resizing is enabled)
 */
class Application
{
private:
	static sf::RenderWindow* s_window;
	static unsigned int s_frameRate;
	static sf::Clock s_timer;
	static sf::Vector2u s_initialWindowSize;
	static sf::RectangleShape* s_background;
	static std::shared_ptr<sf::Font> s_defaultFont;
public:
	/** 
	 * @brief  Initializes the engine
	 * @note   This method needs to be called before Application::run
	 * @param  window: window address
	 */
	static void init(sf::RenderWindow* window);
	/** 
	 * @brief  Runs the program. Updates the engine.
	 * @note   This method needs to be called after Application::init
	 */
    static void run();
	/**
	 * @brief  Returns the default font of an Application
	 * @note   This font is kept in the memory
	 * throughout the whole life of an Application
	 */
	static const sf::Font& getDefaultFont() { return *s_defaultFont; }
	/** 
	 * @brief  Returns window reference. The goal of this
	 * method is to make the window easily accessed.
	 * @retval window reference
	 */
	static sf::RenderWindow& getWindow() { return *s_window; }
	/** 
	 * @brief  Returns the initial window size. Using initial window
	 * size rather than current window size makes sense when
	 * resizing the window is enabled. If window is resized
	 * new entities will be placed based on the current size of window
	 * but ones that are already placed on the screen will not be
	 * repositioned. Instead all entities should be placed
	 * based on the initial size of window when resizing is enabled
	 * @note   If the window is resized, position of all entities
	 * doesn't change, they all get scretched out.
	 * @retval sf::Vector2u initial window size
	 */
	static const sf::Vector2u& getInitialWindowSize() { return s_initialWindowSize; }
	/** 
	 * @brief  Returns mouse position that is mapped to the
	 * world's position of the mouse.
	 * @note   This function is useful
	 * when using a sf::View or when resizing the window is 
	 * enabled
	 * @retval 
	 */
	static sf::Vector2f getMappedMousePosition();
	/** 
	 * @brief  Lets you set a background image that
	 * is rendered before everything else
	 * @param  image: background image
	 * @retval None
	 */
	static void setBackgroundImage(const sf::Texture& image);
	/** 
	 * @brief  Lets you disable the background image
	 * @retval None
	 */
	static void disableBackgroundImage();

	static void exit(int EXIT_CODE = 0);
};

#pragma once
#include <SFML/Graphics.hpp>

namespace sen {
	/** 
		This class is just a wrapper for a sf::RectangleShape class.
		it provides a couple of methods that are handy such as centerBox that centers the box around it's position.
		in future, it will let you blur it's background.
	*/
	class Box : public sf::RectangleShape
	{
	private:
		sf::Shader  *shader = nullptr;
		sf::Sprite  *sprite = nullptr;
		sf::Texture *texture = nullptr;
	public:
		/**
			Default constructor of the Box, it just calls sf::RectangleShape's default constructor
		*/
		Box() : sf::RectangleShape() {}
		/**
			This constructor lets you specify the size of the Box.
			It also calls the centerBox method.

			@param size Size of the box
		*/
		Box(const sf::Vector2f &size);

		/**
			This constructor lets you specify both size and position of the box.
			It also calls the centerBox method.

			@param size Size of the box
			@param pos Position of the box
		*/
		Box(const sf::Vector2f &size, const sf::Vector2f &pos);

		/**
			Draws the box on the target
		
			@param target Target you want to draw the box on
		*/
		void draw(sf::RenderTarget &target);	
		/**
			Let's you blur the background of the box

			@param ammount Ammount of the blur effect
			@param window Background of box
		*/
		void blurBackground(float ammount, sf::RenderWindow& window);
		/**
			Centers itself around it's position
		*/
		void centerBox();
	};
}
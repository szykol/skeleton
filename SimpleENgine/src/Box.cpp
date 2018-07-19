#include "Box.h"

namespace sen {
	void Box::draw(sf::RenderWindow & window)
	{
		if (this->shader)
			window.draw(*this, this->shader);
		else
			window.draw(*this);
	}
	void Box::blurBackground(float ammount, sf::RenderWindow &window)
	{
		this->texture = new sf::Texture();
		this->texture->create(window.getSize().x, window.getSize().y);
		this->texture->update(window);

		/*this->sprite = new sf::Sprite(*texture);
		this->sprite->setTextureRect(sf::IntRect((sf::Vector2i)this->getPosition(), (sf::Vector2i)this->getSize()));*/

		this->setTexture(this->texture);
		
		this->setTextureRect(sf::IntRect((sf::Vector2i)this->getPosition(), (sf::Vector2i)this->getSize()));

		//this->setTextureRect(sf::IntRect(this->getPosition().x, window.getSize().y - this->getPosition().y, this->getSize().x, this->getSize().y * -1));
		this->setOutlineThickness(4.5f);
		this->setOutlineColor(sf::Color::Red);
		//this->setTextureRect(sf::IntRect(0, 600, 800, -600));
		//this->rotate(180);
		this->shader = new sf::Shader();
		this->shader->loadFromFile("Shaders/blur.frag", sf::Shader::Fragment);
		this->shader->setUniform("blur_radius", ammount);
		this->shader->setUniform("texture", this->texture);
	}
}

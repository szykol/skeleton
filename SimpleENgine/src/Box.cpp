#include "Box.h"

namespace sen {
	Box::Box(const sf::Vector2f & size)
	{
		this->setSize(size);
		this->centerBox();
	}
	Box::Box(const sf::Vector2f & size, const sf::Vector2f & pos)
	{
		this->setSize(size);
		this->setPosition(pos);
		this->centerBox();
	}
	void Box::draw(sf::RenderTarget & target)
	{
		target.draw(*this);
	}
	void Box::blurBackground(float ammount, sf::RenderWindow &window)
	{
		this->texture = new sf::Texture();
		this->texture->create(window.getSize().x, window.getSize().y);
		this->texture->update(window);

		this->setTexture(this->texture);
		this->setTextureRect(sf::IntRect((sf::Vector2i)this->getPosition(), (sf::Vector2i)this->getSize()));

		this->shader = new sf::Shader();
		this->shader->loadFromFile("Shaders/blur.frag", sf::Shader::Fragment);
		this->shader->setUniform("blur_radius", ammount);
		this->shader->setUniform("texture", this->texture);
	}
	void Box::centerBox()
	{
		sf::FloatRect bounds = this->getLocalBounds();
		this->setOrigin(sf::Vector2f(bounds.width / 2.f, bounds.height / 2.f));
	}
}

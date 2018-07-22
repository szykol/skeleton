#include "Box.h"

namespace sen {
	Box::Box(const sf::Vector2f & size)
	{
		this->setSize(size);
		this->setOriginMode(OriginMode::CENTER);
	}
	Box::Box(const sf::Vector2f & size, const sf::Vector2f & pos)
	{
		this->setSize(size);
		this->setPosition(pos);
		this->setOriginMode(OriginMode::CENTER);
	}
	void Box::render(sf::RenderTarget & target)
	{
		target.draw(*this);
	}
	void Box::setOriginMode(OriginMode mode)
	{
		if (this->originMode == mode)
			return;

		this->originMode = mode;
		if (this->originMode == OriginMode::CENTER)
			this->setOrigin(this->getSize() / 2.f);
		else
			this->setOrigin(0.f, 0.f);
	}
	void Box::setSize(const sf::Vector2f & size)
	{
		sf::RectangleShape::setSize(size);
		if (this->originMode == OriginMode::CENTER)
			this->setOrigin(this->getSize() / 2.f);
	}
	/*void Box::blurBackground(float ammount, sf::RenderWindow &window)
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
	}*/
}

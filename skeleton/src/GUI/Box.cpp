#include "Box.h"

namespace sen {
	Box::Box(const sf::Vector2f & size)
	{
		setSize(size);
		setOrigin(getSize() / 2.f);
	}
	Box::Box(const sf::Vector2f & size, const sf::Vector2f & pos)
	{
		setSize(size);
		setPosition(pos);
		setOrigin(getSize() / 2.f);
	}
	void Box::render(sf::RenderTarget & target)
	{
		target.draw(*this);
	}
	void Box::setOriginMode(OriginMode mode)
	{
		if (m_originMode == mode)
			return;

		m_originMode = mode;
		if (m_originMode == OriginMode::CENTER)
			setOrigin(getSize() / 2.f);
		else
			setOrigin(0.f, 0.f);
	}
	void Box::setSize(const sf::Vector2f & size)
	{
		sf::RectangleShape::setSize(size);
		if (m_originMode == OriginMode::CENTER)
			setOrigin(getSize() / 2.f);
	}

	void Box::setPosition(float x, float y, float speed)
	{
		sen::Transformable::setPosition(x, y, speed);
	}

	void Box::setPosition(float x, float y)
	{
		sf::Transformable::setPosition(x, y);
	}

	void Box::setPosition(const sf::Vector2f & pos)
	{
		sf::Transformable::setPosition(pos);
	}

	void Box::setPosition(const sf::Vector2f & pos, float speed)
	{
		sen::Transformable::setPosition(pos, speed);
	}

	const sf::Vector2f & Box::getPosition() const
	{
		return sf::Transformable::getPosition();
	}

	void Box::move(float x, float y)
	{
		sf::Transformable::move(x, y);
	}

	void Box::move(const sf::Vector2f & vect)
	{
		sf::Transformable::move(vect);
	}

	/*void Box::blurBackground(float ammount, sf::RenderWindow &window)
	{
		texture = new sf::Texture();
		texture->create(Application::getInitialWindowSize().x, Application::getInitialWindowSize().y);
		texture->update(window);

		setTexture(texture);
		setTextureRect(sf::IntRect((sf::Vector2i)getPosition(), (sf::Vector2i)getSize()));

		shader = new sf::Shader();
		shader->loadFromFile("Shaders/blur.frag", sf::Shader::Fragment);
		shader->setUniform("blur_radius", ammount);
		shader->setUniform("texture", texture);
	}*/
}

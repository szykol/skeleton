//#include "TextButton.h"
//
//namespace sen {
//	TextButton::TextButton(const std::string & string)
//		:InterfaceButton(string)
//	{
//
//	}
//	void TextButton::onHover()
//	{
//		this->setFillColor(sf::Color(25, 25, 25, 170));
//		this->setOutlineColor(sf::Color(222, 222, 222, 170));
//		this->message.setFillColor(Box::getOutlineColor());
//	}
//	void TextButton::onUnhover()
//	{
//		this->setFillColor(sf::Color(sf::Color(25, 25, 25, 50)));
//		this->setOutlineColor(sf::Color(222, 222, 222, 240));
//		this->message.setFillColor(this->getOutlineColor());
//	}
//	void TextButton::onClick()
//	{
//		this->setOutlineColor(sf::Color(0, 198, 0, 190));
//		this->message.setFillColor(Box::getOutlineColor());
//	}
//}